#include "fileio.h"

fileio::fileio(const char* filename){
	readFile(filename);
}
void fileio::readFile(const char* filename){
	ifstream f(filename);
	double temp;
	while(f>>temp){
		x.push_back(temp);
		f>>temp;
		y.push_back(temp);
		f>>temp;
		sigma.push_back(temp);
	}
}
