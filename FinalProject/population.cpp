#include "population.h"

//population::population(int numIndividuals, double planetRadius, double angularVelocity, double sigma, rd& rand, gen& generatorTheta, gen& generatorPhi){
population::population(int numIndividuals, double planetRadius, double angularVelocity,double sigma, int Seed){
	populationSize = numIndividuals;
	//local_random_device = rand;
	seed = Seed;
	local_random_device.seed(Seed);
	local_theta_generator = uniform(0.0,3.14159);
	local_phi_generator = uniform(0.0,2*3.14159);
	meanSpeed = angularVelocity;
	local_speed_generator = uniform(-meanSpeed, meanSpeed);
	sigmaSpeed = sigma;
	r = planetRadius;
	//normal_generator = gaus dist(meanSpeed,sigmaSpeed);
	initPopulation();
}
population::~population(){
	pop.clear();
}
vector<double> population::sphericalToCartesian(vector<double>& spherical){
	//input is {r,theta,phi} output {x,y,z}
	vector<double> cartesian;
	cartesian.push_back(spherical[0]*sin(spherical[1])*cos(spherical[2]));
	cartesian.push_back(spherical[0]*sin(spherical[1])*sin(spherical[2]));
	cartesian.push_back(spherical[0]*cos(spherical[1]));
	return cartesian;
} 
double population::getMagnitude(vector<double>& v){
	return sqrt( v[0]*v[0] + v[1]*v[1] + v[2]*v[2] );
}
double population::getOpeningAngle(vector<double>& v1, vector<double>& v2){
	if(v1[0]==v2[0] && v1[1]==v2[1] && v1[2] == v2[2]) return 0;
	return acos( (v1[0]*v2[0] + v1[1]*v2[1] + v1[2]*v2[2])/ (getMagnitude(v1)*getMagnitude(v2)));
	
}
double population::getOpeningAngleSpherical(vector<double>& sph1, vector<double>& sph2){
	vector<double> cart1= sphericalToCartesian(sph1);
	vector<double> cart2= sphericalToCartesian(sph2);
	
	return getOpeningAngle(cart1,cart2);
}
vector<double> population::formVector(double v1, double v2, double v3){
	vector<double> v;
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	return v;
}
/*vector<double> population::findMoveVector(vector<double>& v1, vector<double>& v2, double omega){
	
	//go to cartesian, fix z component in v3 such that v3 is in between v1 and v2 and omega degrees separated from v1
	//solve for x3,y3 and return spherical vector
	double psi = getOpeningAngleSpherical(v1, v2);
	double omega_bar = psi - omega;
	
	vector<double> c1 = sphericalToCartesian(v1);
	vector<double> c2 = sphericalToCartesian(v2);
	double A = getMagnitude(c1);

	vector<double> c3;
	double Numerator = A*cos(omega) - (c1[1]*A*cos(omega_bar))/c2[1] + (c1[1]*c2[2]*c1[2])/c2[1] - c1[2]*c1[2];
	double Denominator = c1[0] - (c1[1]*c2[0])/c2[1];
	c3.push_back(Numerator/Denominator);
	//c3.push_back(sqrt(abs(c1[0]*c1[0] + c1[1]*c1[1] - c3[0]*c3[0])));// sometimes y3 is negative.. absval?
	c3.push_back(sqrt( A*A - c3[0]*c3[0] - c3[2]*c3[2] ));
	c3.push_back(c1[2]);
	
	//have new cartesian vector, change to spherical and return
	vector<double> s3;
	s3.push_back(-1);//we dont care about r, its handled elsewhere
	s3.push_back(atan2(c3[1],c3[0]));
	s3.push_back(atan2( sqrt(c3[0]*c3[0] + c3[1]*c3[1]),c3[2] ));
	
	return s3;
}*/
//trying different method for movement
vector<double> population::findMoveVector(vector<double>& v1, vector<double>& v2, double omega){
	double newtheta = local_speed_generator(local_random_device);
	double newphi = sqrt(omega*omega - newtheta*newtheta);
	
	//roll to see if we add or minus phi
	if(local_phi_generator(local_random_device)/(2*3.14159) > 0.5){ newphi = -1* newphi;}
	
	
	vector<double> newVector;
	newVector.push_back(-1);
	newVector.push_back(v1[1] + newtheta);
	newVector.push_back(v1[2] + newphi);
	
	return newVector;
}

void population::moveIndividuals(){
	double theta,phi;
	//essentially for each individual generate a random point on the sphere, then have the individual move towards that point up to there maximum angular movement per day
	//if the point is close, then stop at that point
	vector<double> randomVec;
	vector<double> indivdVec;
	vector<double> moveVec;
	double angle;
	for(int i=0; i<pop.size(); i++){
		theta = local_theta_generator(local_random_device);
		phi = local_phi_generator(local_random_device);
		randomVec = formVector(r,theta,phi);
		indivdVec = formVector(r,pop[i]->getTheta(),pop[i]->getPhi());
		angle=getOpeningAngleSpherical(randomVec,indivdVec);
		
		if(angle <= pop[i]->getSpeed()){
			pop[i]->setPosition(r,theta,phi);			
		}
		else{
			moveVec = findMoveVector(indivdVec,randomVec,pop[i]->getSpeed());
			pop[i]->setPosition(r, moveVec[1], moveVec[2]);
		}
		
		randomVec.clear();
		indivdVec.clear();
		moveVec.clear();
		//form vector from random r,theta,phi and dot with individual position vector, if opening angle is less than max movement, set position to random vec position
	}
}
void population::setMeanSpeed(double mean){
	meanSpeed = mean;
}
void population::setSigmaSpeed(double sigma){
	sigmaSpeed = sigma;
}
void population::setSpeeds(){
	//draw gaussian deviates here maybe
	for(int i=0; i<pop.size(); i++){
		pop[i]->setSpeed(meanSpeed);
	}
}
void population::initPopulation(){
	double theta,phi;
	for(int i=0; i<populationSize; i++){
		theta = local_theta_generator(local_random_device);
		phi = local_phi_generator(local_random_device);
		individual* person = new individual(r,theta,phi);
		pop.push_back(person);
	}
	setSpeeds();
}
double population::getPopulationSize(){
	return populationSize;
}	
void population::setR(double radius){
	r = radius;
}
void population::printPositions(){
	for(int i=0; i<pop.size(); i++){
		pop[i]->printPosition();
	}
}
void population::storeOldInd(){
	for(int i=0; i<populationSize; i++){
		individual* person = new individual(r,pop[i]->getTheta(),pop[i]->getPhi());
		oldpop.push_back(person);
	}
}
void population::getMovement(){
		vector<double> v1;
		vector<double> v2;
	for(int i=0; i<populationSize; i++){
		v1 = formVector(r, pop[i]->getTheta(), pop[i]->getPhi());
		v2 = formVector(r, oldpop[i]->getTheta(), oldpop[i]->getPhi());
		cout<<getOpeningAngleSpherical(v1,v2)<<endl;
		v1.clear();
		v2.clear();
	}
}
vector<individual*> population::getPopulation(){
	return pop;
}
double population::getR(){
	return r;
}
void population::updatePopulation(){
	for(int i=0; i<populationSize; i++){
		if(pop[i]->isInfectious()){
			pop[i]->decreaseInfectiousDays();
		}
		pop[i]->updateStatuses();
	}
}
bool population::hasNoInfections(){
	for(int i=0; i<populationSize; i++){
		if(pop[i]->isInfectious()) return false;
	}
	return true;
}
double population::getNumExposed(){
	double numExposed = 0;
	for(int i=0; i<populationSize; i++){
		if(pop[i]->isExposed()) numExposed++;
	}
	return numExposed;
}
double population::getNumInfected(){
	double numInfected = 0;
	for(int i=0; i<populationSize; i++){
		if(pop[i]->isInfectious()) numInfected++;
	}
	return numInfected;
}
	

