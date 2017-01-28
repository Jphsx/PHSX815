#include "pandemic.h"


pandemic::pandemic(population*& pop, disease*& dis, int Seed){
	p = pop;
	d = dis;
	local_random_device.seed(Seed);
	local_infection_roll = uniform(0.0,1.0);
	populationLottery = uniformInt(0,p->getPopulationSize()-1);
}
void pandemic::spreadDisease(){
	double infectionProbability;
	double infectionRoll;
	vector<double> p1; //spherical vector of person
	vector<double> p2;
	//we want i to be an infected person, if its true infect all nearby j
	for(int i=0; i<p->getPopulation().size(); i++){
		for(int j=0; j<p->getPopulation().size(); j++){
			if(!p->getPopulation()[i]->isInfectious()){
				 break;
			}
			else{//infected, spread disease
				if(p->getPopulation()[j]->isSusceptible()){
					p1= p->formVector(p->getR(), p->getPopulation()[i]->getTheta(), p->getPopulation()[i]->getPhi());
					p2= p->formVector(p->getR(), p->getPopulation()[j]->getTheta(), p->getPopulation()[j]->getPhi());
					infectionProbability = d->getInfectionProbability(p->getOpeningAngleSpherical(p1,p2));
					infectionRoll = local_infection_roll(local_random_device);
					if(infectionRoll <= infectionProbability){
						p->getPopulation()[j]->becomeInfected(d->getDaysOfInfection());
					}
				}
			}
			p2.clear();
			p1.clear();	
		}
	}
}
void pandemic::initOutbreak(int nImmune, int nInitialInfected){
	//select random individuals to have initial immunity
	int counter = nImmune;
	int randomIndex;
	while(counter != 0){
		randomIndex = populationLottery(local_random_device);
		if(p->getPopulation()[randomIndex]->isSusceptible()){
			p->getPopulation()[randomIndex]->becomeImmune();
			counter--;
		}
	}
	counter = nInitialInfected;
	while(counter != 0){
		randomIndex = populationLottery(local_random_device);
		if(p->getPopulation()[randomIndex]->isSusceptible()){
			p->getPopulation()[randomIndex]->becomeInfected(d->getDaysOfInfection());
			counter--;
		}
	}	

}
