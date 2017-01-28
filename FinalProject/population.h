#ifndef _POP_
#define _POP_
#include <vector>
#include "individual.h"
#include <random>
#include <iostream>
#include <cmath>
using namespace std;
//typedef random_device rd;
typedef std::mt19937 gen;
//typedef uniform_int_distribution<> Intgen;
typedef normal_distribution<double> gaus;
typedef uniform_real_distribution<double> uniform;
//gausdistribution(5.0,2.0) mean sigma

class population{
	
	
	private:
	vector<individual*> pop;
	void initPopulation();
	void setSpeeds();
	
	//should generate numbers between [0,2pi] and [0,pi]
	int seed;
	gen local_random_device;
	//gen generator;
	uniform local_theta_generator;
	uniform local_phi_generator;
	//gaus normal_generator;
	uniform local_speed_generator;
	
	int populationSize;
	double meanSpeed;
	double sigmaSpeed;
	double r; //track planet size
	
	

	//population is in control of moving individuals
	//so population dynamics (speed) etc
	//might implement speed as gaussian deviates later on

	public:
		//population(int numIndividuals, double planetRadius, double angularVelocity, double sigma, rd& rand, gen& generatorTheta, gen& generatorPhi);
		population(int numIndividuals, double planetRadius, double angularVelocity, double sigma, int Seed);
		~population();
		void moveIndividuals();
		void setMeanSpeed(double mean);
		void setSigmaSpeed(double sigma);
		
		double getPopulationSize();
		void setR(double radius);
		double getR();
		vector<individual*> getPopulation();
		void updatePopulation();
		bool hasNoInfections();
		double getNumExposed();///ran at the end for infection rate
		double getNumInfected();// ran on day 2 to see secondary infections

		//vector utility stuff
		vector<double> sphericalToCartesian(vector<double>& spherical);
		double getOpeningAngle(vector<double>& v1, vector<double>& v2);
		double getMagnitude(vector<double>& v);
		double getOpeningAngleSpherical(vector<double>& sph1, vector<double>& sph2);
		vector<double> formVector(double v1, double v2, double v3);
		vector<double> findMoveVector(vector<double>& v1, vector<double>& v2, double omega);

		void printPositions();
		//debug
		void storeOldInd();
		vector<individual*> oldpop;
		void getMovement();//look at angular displacement between old and new
		
		
		

};
#endif
