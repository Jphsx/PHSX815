#ifndef _TRIP_
#define _TRIP_
#include "city.h"
#include <random>
#include <cmath>
#include <vector>
#include <iostream>//debugging
using namespace std;
//each class instance will have a pointer to a master array of cities
//and access to a RNG outside of the class
typedef std::random_device RNG;
typedef std::mt19937 RNGgen;
typedef uniform_int_distribution<> RNGInt;

class cityTraversals{

	public:
		cityTraversals(vector<city*>& master, RNGInt& generator, RNGgen& g);
		//child constructor
		cityTraversals(int size, vector<city*> trip);
		~cityTraversals();
		int mastersize;
		//RNGInt gen;
		//RNGgen rng;		
		//vector<city*> masterCityList;
		
		void initTrip(vector<city*> & master, RNGInt& gen, RNGgen& rng);
		vector<city*>& getTrip();
		double getTripCost();
		void setTrip(vector<city*> trip);
		//void printTrip();

	private:
		vector<city*> traversals;
		double getCityDistance(city* a, city* b);
};
#endif
