#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;
double getAverage(vector<double> v){
	double sum =0.0;
	for(int i=0;i<v.size();i++){
		sum += v[i];	
		//cout<<v[i]<<" ";	
	}
	//cout<<endl;
	return sum/v.size();
}
double getRMS(vector<double> v){
	double mu = getAverage(v);
	double sum=0.0;
	for(int i=0; i<v.size(); i++){
		sum += (v[i]-mu)*(v[i]-mu);		
	}
	return sqrt(sum/v.size());
}

int main(){

	//for 3 field file
	vector<double> exposed;
	vector<double> day;
	vector<double> thetac;
	//const char* file = "../output/nExposedAndnDays_Static.dat";
	//const char* file = "../output/nExposedAndnDays_Mobile.dat";
	//const char* file = "../output/nExposedAndnDays_Static_Probable.dat";
	//const char* file = "../output/SecondaryInfections_Mobile.dat";
	//const char* file = "../output/SecondaryInfections_Static.dat";
	const char* file = "../output/SecondaryInfections_Static_Probable.dat";
	
	ifstream f(file);
	double temp;
/*	while(!f.eof()){
	//	cout<<"TEMP "<<temp<<endl;
		for(int i=0; i<25; i++){
			f>>temp;
			exposed.push_back(temp);
			f>>temp;
			day.push_back(temp);
			f>>temp;
			thetac.push_back(temp);
			//f>>temp;
		}
		cout<<getAverage(exposed)<<" "<<getRMS(exposed)<<" "<<getAverage(day)<<" "<<getRMS(day)<<" "<<thetac[0]<<endl;
		exposed.clear();
		day.clear();
		thetac.clear();
	}*/
	//for 2 field file
	vector<double> secondary;
	while(!f.eof()){
		for(int i=0; i<25; i++){
			f>>temp;
			secondary.push_back(temp);
			f>>temp;
			thetac.push_back(temp);
		}
		cout<<getAverage(secondary)<<" "<<getRMS(secondary)<<" "<<thetac[0]<<endl;
		secondary.clear();
		thetac.clear();
	}

}
