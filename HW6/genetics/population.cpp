#include "population.h"

population::population(double populationSize, RNGInt& generator, vector<city*>& master, RNGgen& g){
	masterCityList = master;
	//gen = generator;
	//rng = g;
	popsize = populationSize;
	createPopulation(populationSize, generator, g);
}
population::population(vector<city*>& master){
	masterCityList = master;
}
population::~population(){
	for(int i=0; i<pop.size(); i++){
		
			//for(int k=0; k<pop[i]->mastersize; k++){
			//	delete pop[i];
			
			//}
			pop[i]->getTrip().clear();
		
	}
	pop.clear();
	
}
void population::createPopulation(double populationSize, RNGInt& generator, RNGgen& g){
	for(int i=0; i<populationSize; i++){
		cityTraversals* c = new cityTraversals(masterCityList, generator, g);
		pop.push_back(c);
	}
}
vector<cityTraversals*>& population::getPopulation(){
	return pop;
}
vector<cityTraversals*> population::getRandomSubSample(double sampleSize, RNGInt& generator, RNGgen& g){//this probably needs modified to take rng ref
	//uniform_int_distribution<> dist(0,masterCityList.size()-1);
	int randIndex;
	vector<cityTraversals*> sample;
	vector<city*> t;
	for(int i=0; i<sampleSize; i++){
		randIndex=generator(g);
		//try hard copying
		for(int j =0; j<pop[randIndex]->mastersize; j++){
			city* c = new city(getPopulation()[randIndex]->getTrip()[j]->getX(), getPopulation()[randIndex]->getTrip()[j]->getY());
			t.push_back(c);			
		}
		cityTraversals* ct = new cityTraversals(masterCityList.size(), t);
		
		//sample.push_back(pop[randIndex]);	
		sample.push_back(ct);
	}
		/*for(int j=0; j<sample.size(); j++){
		for(int k=0; k<sample[j]->getTrip().size(); k++){
		cout<<"("<<sample[j]->getTrip()[k]->getX()<<","<<sample[j]->getTrip()[k]->getY()<<") ";
	}
	cout<<endl;
	}*/
		
	return sample;
}
void population::addTraversal(cityTraversals* trip){
	pop.push_back(trip);
}
double population::getpopsize(){
		return pop.size();
	}
