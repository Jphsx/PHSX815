#include "cityTraversals.h"

//cityTraversals::cityTraversals(vector<city*>& master, RNGInt& generator, RNGgen& g){
cityTraversals::cityTraversals(vector<city*> & master, RNGInt& generator, RNGgen& g){
	//masterCityList = master;
	mastersize = master.size();
	//gen = generator;
	//rng = g;
	initTrip(master, generator, g);
}
cityTraversals::cityTraversals(int size, vector<city*> trip){
//cityTraversals::cityTraversals(
	mastersize= size;
	//masterCityList = master;
	traversals = trip;
}
cityTraversals::~cityTraversals(){
	//for(int i=0; i<traversals.size(); i++){
	//	delete traversals[i];
	//}
	traversals.clear();
}
void cityTraversals::initTrip(vector<city*> &master ,RNGInt& gen, RNGgen& rng){
	//hard copy master list then scramble randomly
	for(int i=0; i< mastersize; i++){
		traversals.push_back(master[i]);
	}
	//uniform_int_distribution<> dist(0,masterCityList.size()-1);
	//generate 2 random numbers swap those traversals
	//perform 3n swaps
	int randIndex1;
	int randIndex2;
	
	city* temp;
	for(int i=0; i< 3*mastersize; i++){		
		randIndex1=gen(rng);
		randIndex2=gen(rng);
		//cout<<randIndex1<<" "<<randIndex2<<endl;
		temp = traversals[randIndex1];
		traversals[randIndex1] = traversals[randIndex2];
		traversals[randIndex2] = temp;		
	}
}
double cityTraversals::getCityDistance(city* a, city* b){
	return sqrt(pow(b->getX()-a->getX(),2) + pow(b->getY()-a->getY(),2));
}
double cityTraversals::getTripCost(){
	double cost=0.0;
	for(int i=0; i<traversals.size()-1; i++){
		cost+= getCityDistance(traversals[i], traversals[i+1]);
	}
	return cost;
}
vector<city*>& cityTraversals::getTrip(){
	return traversals;
}
void cityTraversals::setTrip(vector<city*> trip){
	traversals = trip;
}

