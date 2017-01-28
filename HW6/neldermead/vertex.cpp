#include "vertex.h"

vertex::vertex(){}
vertex::vertex(int dimension){
	dim = dimension;	
}
vertex::vertex(int dimension, double functionValue, vector<double> xpoints){
	dim = dimension;
	f = functionValue;
	xi = xpoints;
}
void vertex::setdim(int dimension){
	dim = dimension;
}
void vertex::setf(double functionValue){
	f = functionValue;
}
void vertex::setxi(vector<double> xpoints){
	xi = xpoints;
}
int vertex::getdim(){
	return dim;
}
double vertex::getf() const {
	return f;
} 
vector<double> vertex::getxi(){
	return xi;
}
bool operator>=(const vertex& lhs, const vertex& rhs)
{
    return (lhs.getf() >= rhs.getf());
}
bool operator<=(const vertex& lhs, const vertex& rhs)
{
	return (lhs.getf() <= rhs.getf());
}
//int main(){}
