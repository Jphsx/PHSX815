#ifndef _GENE_
#define _GENE_


#include "city.h"
#include "cityTraversals.h"
#include "population.h"
#include "cityio.h"
#include <random>
#include <iostream>

typedef std::random_device RNG;
typedef std::mt19937 RNGgen;
typedef uniform_int_distribution<> RNGInt;

using namespace std;
class genetic{
public:
	population* evolvePopulation(population* p, double sampleSize, RNGInt& gen, RNGgen& g, RNGInt& gen2);
	
	//returns the index of best candidate	
	int selectFittest(vector<cityTraversals*>& subSample);
	
	cityTraversals* breed(cityTraversals* parent1, cityTraversals* parent2, RNGInt& gen, RNGgen& g);
	void mutate(cityTraversals*& candidate, RNGInt& gen, RNGgen& g);
	bool contains(vector<city*> set, city* c);
	vector<city*> removeSubset(cityTraversals* set, vector<city*> subset);
	
};
#endif
