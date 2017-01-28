#ifndef _EARTH_
#define _EARTH_
#include <random>
#include "population.h"
#include <iostream>
#include "disease.h"
#include "pandemic.h"

using namespace std;
//typedef std::random_device rd;
typedef std::mt19937 gen;
//typedef uniform_int_distribution<> Intgen;
typedef uniform_real_distribution<double> uniform;
typedef normal_distribution<double> gaus;
class planet{
	private:
		population* people;
		double planetRadius;
		disease* flu;
		pandemic* outbreak;
		int seed;

	public:
		planet(double size);
		~planet();
		//void initPeople(int numIndividuals,double angularVelocity, double sigma, rd& rand, gen& generatorTheta, gen& generatorPhi);
		void initPeople(int numIndividuals, double angularVelocity, double sigma, int Seed);
		void initDisease(int mode, double parameter, double infectedDays);
		void initPandemic(int nImmune, int nInitialInfected);
		void nextDay();
		population* getPeople();
	
		
		void printPeople();
		
		void saveOldPositions();
	
};
#endif
