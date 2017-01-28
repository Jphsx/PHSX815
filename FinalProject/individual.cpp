#include "individual.h"
individual::individual(double radius, double polar, double azimuth){
	r = radius;
	theta = polar;
	phi = azimuth;
	susceptible = true;
	exposed = false;
	infectious = false;
	immune = false;
	infectiousDays = -1;
}
void individual::setR(double radius){
	r = radius;
}
void individual::setTheta(double polar){
	theta = polar;
}
void individual::setPhi(double azimuth){
	phi = azimuth;
}
void individual::setPosition(double radius, double polar, double azimuth){
	r = radius;
	theta = polar;
	phi = azimuth;
}
void individual::setSpeed(double omega){
	speed = omega;
}
void individual::setInfectiousDays(double days){
	infectiousDays = days;
}
void individual::setSusceptible(bool state){
	susceptible = state;
}
void individual::setExposed(bool state){
	exposed = state;
}
void individual::setInfectious(bool state){
	infectious = state;
}
void individual::setImmune(bool state){
	immune = state;
}
void individual::decreaseInfectiousDays(){
	infectiousDays--;
}
void individual::becomeInfected(int days){
	susceptible = false;
	exposed = true;
	infectious = true;
	infectiousDays = days;
}
void individual::becomeImmune(){
	susceptible = false;
	immune = true;
}
void individual::updateStatuses(){
	if(exposed && infectiousDays == 0) immune = true;
	if(exposed) susceptible = false;
	if(immune) susceptible = false;
	if(immune) infectious = false;
	if(infectiousDays == 0) infectious = false;
}
double individual::getR(){
	return r;
}
double individual::getTheta(){
	return theta;
}
double individual::getPhi(){
	return phi;
}
double individual::getSpeed(){
	return speed;
}
bool individual::isSusceptible(){
	return susceptible;
}
bool individual::isExposed(){
	return exposed;
}
bool individual::isInfectious(){
	return infectious;
}
bool individual::isImmune(){
	return immune;
}
void individual::printPosition(){
	cout<<"R: "<<r<<" Theta: "<<theta<<" Phi: "<<phi<<" isInfectious: "<<infectious<<" isImmune: "<<immune<< " InfectiousDays: "<<infectiousDays<<endl;
}
