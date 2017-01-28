
#include "planet.h"
#include <iostream>

int main(){
	int seed = 1;
	int populationSize=1000;
	double populationSpeed=0.02;
	double speedSigma=1.0; //unused
	double planetRadius = 1;

	int diseaseMode = 1;
	double diseaseParameter = 0;//either critical angle or resolution Parameter
	int infectiousDays = 10;
	int nInitiallyImmune = 0;
	int nInitiallyInfected = 1;
	
//testing set
/*	planet* p = new planet(planetRadius);
	p->initPeople(populationSize,populationSpeed,speedSigma,seed);
	p->initDisease(diseaseMode,diseaseParameter,infectiousDays);
	p->initPandemic(nInitiallyImmune,nInitiallyInfected);

	
	int days=1;;
	while(!p->getPeople()->hasNoInfections()){
		cout<<"DAY "<<days<<endl;
		p->printPeople();
		p->nextDay();
		days++;
		cout<<endl;
	}
	cout<<"DAY "<<days<<endl;
	p->printPeople(); */

////////test for secondary infections (static model) mode 0 i will be seed and mobile model mode 0
//mode 1 omega=0
	/*while(diseaseParameter<1.5){
		for(int i=0; i<25; i++){
			planet* p = new planet(planetRadius);
			p->initPeople(populationSize,populationSpeed,speedSigma,i);
			p->initDisease(diseaseMode,diseaseParameter,infectiousDays);
			p->initPandemic(nInitiallyImmune,nInitiallyInfected);
			p->nextDay();
			cout<<p->getPeople()->getNumInfected()<<" "<<diseaseParameter<<endl;
			delete p;
	
		}
		diseaseParameter+=0.05;
	}*/

////////test for n days until no infections and infection rate (static model) mode 0/ mobile model 
	int days = 1;
	while(diseaseParameter<1.5){
		for(int i=0; i<25; i++){
			planet* p = new planet(planetRadius);
			p->initPeople(populationSize,populationSpeed,speedSigma,i);
			p->initDisease(diseaseMode,diseaseParameter,infectiousDays);
			p->initPandemic(nInitiallyImmune,nInitiallyInfected);
			while(!p->getPeople()->hasNoInfections()){
				p->nextDay();
				days++;
			}
			cout<<p->getPeople()->getNumExposed()<<" "<<days<<" "<<diseaseParameter<<endl;
			days = 1;
			delete p;
		}
		
		diseaseParameter+=0.05;
		//days = 1;
	}
	

}
