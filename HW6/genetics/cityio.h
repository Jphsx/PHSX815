#ifndef _IO_
#define _IO_
#include <iostream>
#include <fstream>
#include <vector>
#include "city.h"
using namespace std;
class cityio{
	
	public:
		cityio(const char* filename);
		vector<double> cityNum;
		vector<double> x;
		vector<double> y;
		void readFile(const char* filename);
		void makeMasterList();
		vector<city*> cityMasterList;
		vector<city*>& getMasterList();
};
#endif
