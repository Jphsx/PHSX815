#include "disease.h"

disease::disease(int mode, double parameter, double infectedDays){
	if(mode == 0){
		SpatiallyCertain = true;
		SpatiallyProbable = false;
		criticalAngle = parameter;
	}
	else{
		SpatiallyCertain = false;
		SpatiallyProbable = true;
		resolutionParameter = parameter;
	}
	daysOfInfection = infectedDays;
}
double disease::getInfectionProbability(double angle){
	if(SpatiallyCertain){
		if(angle <= criticalAngle) return 1;
		else return 0;
	}
	else{
		return exp(-0.5*pow(angle/resolutionParameter,2) );
	}
}
double disease::getDaysOfInfection(){
	return daysOfInfection;
}
