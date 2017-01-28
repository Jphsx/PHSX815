#include "cityio.h"

cityio::cityio(const char* filename){
	readFile(filename);
	makeMasterList();
}
void cityio::readFile(const char* filename){
	ifstream f(filename);
	double temp;
	while(f>>temp){
		cityNum.push_back(temp);
		f>>temp;
		x.push_back(temp);
		f>>temp;
		y.push_back(temp);
	}
}
void cityio::makeMasterList(){
	for(int i=0; i<x.size(); i++){
		city* c = new city(x[i], y[i]);
		cityMasterList.push_back(c);
	}
}
vector<city*>& cityio::getMasterList(){
	return cityMasterList;
}
