#ifndef _DIS_
#define _DIS_
#include <cmath>
class disease{
	private:
		//mode 0
		bool SpatiallyCertain;
		//mode 1
		bool SpatiallyProbable;
		double criticalAngle;
		double resolutionParameter;
		double daysOfInfection;
		

	public:
		disease(int mode, double parameter, double infectedDays);
		double getInfectionProbability(double angle);
		double getDaysOfInfection();
		
	
};
#endif
