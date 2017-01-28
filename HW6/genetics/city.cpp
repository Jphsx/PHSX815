#include "city.h"

city::city(double x, double y){
	X = x;
	Y = y;
}
//city::~city(){
//	X.clear();
//	Y.clear();
//}
double city::getX(){
	return X;
}
double city::getY(){
	return Y;
}
void city::setX(double x){
	X = x;
}
void city::setY(double y){
	Y = y;
}
