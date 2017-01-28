#include "planet.h"
planet::planet(double size){
	planetRadius = size;
}
planet::~planet(){
	delete people;
	delete flu;
	delete outbreak;
}
//void planet::initPeople(int numIndividuals,double angularVelocity, double sigma, rd& rand, gen& generatorTheta, gen& generatorPhi){
void planet::initPeople(int numIndividuals, double angularVelocity, double sigma, int Seed){
	//people = new population(numIndividuals,planetRadius, angularVelocity, sigma, rand, generatorTheta, generatorPhi);
	people = new population(numIndividuals, planetRadius, angularVelocity, sigma, Seed);
	seed = Seed;
}
void planet::initDisease(int mode, double parameter, double infectedDays){
	flu = new disease(mode,parameter,infectedDays);
}
void planet::initPandemic(int nImmune, int nInitialInfected){
	outbreak = new pandemic(people,flu,seed);
	outbreak->initOutbreak(nImmune, nInitialInfected);
}
void planet::nextDay(){
	people->moveIndividuals();
	outbreak->spreadDisease();
	people->updatePopulation();
}
population* planet::getPeople(){
	return people;
}
void planet::printPeople(){
	people->printPositions();
}

//debug
void planet::saveOldPositions(){//make a deep copy to look at movment
	people->storeOldInd();
}
