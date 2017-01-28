#ifndef _pandemic_
#define _pandemic_
#include "population.h"
#include "disease.h"
#include <random>
#include <vector>

typedef std::mt19937 gen;
typedef uniform_real_distribution<double> uniform;
typedef uniform_int_distribution<> uniformInt;
class pandemic{
	//this class manages dynamics between disease and population
	private:	
		population* p;
		disease* d;
		gen local_random_device;
		int seed;
		uniform local_infection_roll;
		uniformInt populationLottery;
		
		

	public:
		pandemic(population*& pop, disease*& dis, int Seed);
		void spreadDisease();
		void initOutbreak(int nImmune, int nInitialInfected);
		
};
#endif
