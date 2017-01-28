#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
class fileio{
	public:
		fileio(const char* filename);
		vector<double> x;
		vector<double> y;
		vector<double> sigma;
		void readFile(const char* filename);

};
