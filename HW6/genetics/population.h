#ifndef _Pop_
#define _Pop_

#include <vector>
#include "cityTraversals.h"
#include "city.h"
#include <random>
using namespace std;
typedef std::random_device RNG;
typedef std::mt19937 RNGgen;
typedef uniform_int_distribution<> RNGInt;
class population{

	public:
		vector<city*> masterCityList;
		//RNGInt gen;
		//RNGgen rng;
		population(double populationSize, RNGInt& generator, vector<city*>& master, RNGgen& g);//////
		~population();
		population(vector<city*>& master);
		vector<cityTraversals*>& getPopulation();
		vector<cityTraversals*> getRandomSubSample(double sampleSize, RNGInt& generator, RNGgen& g);
		void addTraversal(cityTraversals* trip);
		double popsize;
		double getpopsize();

	private:
		void createPopulation(double populationSize, RNGInt& generator, RNGgen& g);
		vector<cityTraversals*> pop;
};
#endif
