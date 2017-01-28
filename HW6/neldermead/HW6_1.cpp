

#include <iostream>
#include <cmath>
#include <iomanip>
#include "vertex.h"
#include <vector>
#include "fileio.h"
using namespace std;
//global neldermead params
double rho = 1.0;
double chi = 2.0;
double gamm = 0.5;
double sigma = 0.5;

//for Chisq minimization hax
vector<double> x;
vector<double> y;
vector<double> sig;

//global vertex array for nelder mead minimization
vector<vertex*> v; 

double func1(vector<double> xi){
	double x,y;
	x = xi[0];
	y = xi[1];
	return 100*(y-x*x)*(y-x*x) + (1-x)*(1-x);
}
double func2(vector<double> xi){
	double x,y;
	x=xi[0];
	y=xi[1];
	return (1+(x+y+1)*(x+y+1)*(19-14*x+3*x*x-14*y+6*x*y+3*y*y)) * ( 30+(2*x-3*y)*(2*x-3*y)*(18-32*x+12*x*x+48*y-36*x*y+27*y*y));
}
double testfunc(vector<double> xi){
	double x,y;
	x=xi[0];
	y=xi[1];
	return x*x+y*y;
}
double func3(vector<double> xi){
	double Vo,A,w,phi,chisq;
	Vo = xi[0];
	A = xi[1];
	w = xi[2];
	phi = xi[3];
	chisq =0.0;
	for(int i=0; i<x.size(); i++){
		chisq+= pow(((Vo+A*sin(w*x[i] - phi))-y[i])/sig[i],2);
	}
	return chisq;
}
void sortVals(){
	//selection sort courtesy of wikipedia

	for (int j = 0; j < v.size(); j++) {
   		 int iMin = j;
   		for (int i = j+1; i < v.size(); i++) {
        		if (v[i]->getf() < v[iMin]->getf()) {
            /* found new minimum; remember its index */
            		iMin = i;
        		}
   		 }
	 	if(iMin != j) {
			vertex* temp = v[j];
			v[j] = v[iMin];
			v[iMin] = temp;
    		}
	}
	
}
//uses global instance of points (due to recursion)
vector<double> computeCentroid(){
	//computes average of all but last vertex
	vector<double> cent;
	for( int i=0; i<v[0]->getxi().size(); i++){
		cent.push_back(0);
	}

	for(int i=0; i<v.size()-1; i++){
		for(int j=0; j<v[0]->getxi().size(); j++){
			cent[j]+=v[i]->getxi()[j];
		}
	}
	for( int i=0; i<v[0]->getxi().size(); i++){
		cent[i]= cent[i]/v[0]->getxi().size();
	}
	return cent;
}
vector<double> computeReflection(){
	vector<double> xr;
	vector<double> xbar = computeCentroid();
	for(int i=0; i< v[0]->getxi().size(); i++){
		xr.push_back((1+rho)*xbar[i] - rho*v[v.size()-1]->getxi()[i] );
	}
	return xr;
}
vector<double> computeExpansion(){
	vector<double> xe;
	vector<double> xbar = computeCentroid();
	for(int i=0; i< v[0]->getxi().size(); i++){
		xe.push_back((1+rho*chi)*xbar[i] - rho*chi*v[v.size()-1]->getxi()[i] );
	}
	return xe;
}
vector<double> computeContraction_out(){
	vector<double> xc;
	vector<double> xbar = computeCentroid();
	for(int i=0; i< v[0]->getxi().size(); i++){
		xc.push_back((1+rho*gamm)*xbar[i] - rho*gamm*v[v.size()-1]->getxi()[i] );
	}
	return xc;
}
vector<double> computeContraction_in(){
	vector<double> xcc;
	vector<double> xbar = computeCentroid();
	for(int i=0; i< v[0]->getxi().size(); i++){
		xcc.push_back((1-gamm)*xbar[i] + gamm*v[v.size()-1]->getxi()[i] );
	}
	return xcc;
}
bool replaceVert(int index, vector<double> points, double(*f)(vector<double>)){
	v[index]->setxi(points);
	v[index]->setf(f(points));
	return false;
}
void performShrink(double(*f)(vector<double>)){
	vector<double> vi;
	for(int i=1; i<v.size(); i++){
		for( int j=0; j<v[0]->getxi().size(); j++){
			vi.push_back(v[0]->getxi()[j] + sigma* (v[i]->getxi()[j] - v[0]->getxi()[j] )  );
		}
		replaceVert(i,vi,f);
		vi.clear();
	}
}
bool stoppingConditionMet(vector<double> oldFs){
	//add up all the old fs and - sum of all new fs
	// if difference is less than stopping criteria return true
	double oldsum=0.0;
	double newsum=0.0;
	for(int i=0; i<oldFs.size(); i++){
		oldsum+= oldFs[i];
		newsum+= v[i]->getf();
	}
	if(abs(oldsum-newsum) < 1e-13) return true;
	else return false;
}
double NelderMead(double(*f)(vector<double>) ){
	
	bool flag=true;

	//for stopping conditions make a copy of function values
	vector<double> oldFs;
	for(int i=0; i<v.size(); i++){
		oldFs.push_back(v[i]->getf());
	}

	// sort vertices	
	sortVals();
	
	//compute and compare reflection
	vector<double> ref = computeReflection();
	if(v[0]->getf() <= f(ref) && f(ref) < v[v.size()-2]->getf() ){
		//accept xr
	 	flag = replaceVert(v.size()-1,ref,f);
	}
	//expand
	if(flag && f(ref) < v[0]->getf()){
		vector<double> exp = computeExpansion();
		(f(exp) < f(ref)) ? flag = replaceVert(v.size()-1,exp,f) : flag = replaceVert(v.size()-1,ref,f);
	}
	//contract
	if(flag && f(ref) > v[v.size()-2]->getf()){
		//outside contraction
		if(v[v.size()-2]->getf() <= f(ref) && f(ref) < v[v.size()-1]->getf()){
			vector<double> cont_out = computeContraction_out();
			(f(cont_out) <= f(ref)) ? flag = replaceVert(v.size()-1,cont_out,f) : 0;
		}
		//inside contraction
		else{
			vector<double> cont_in = computeContraction_in();
			(f(cont_in) < v[v.size()-1]->getf()) ? flag = replaceVert(v.size()-1,cont_in,f) : 0;
		}
	}
	//shrink
	if(flag) performShrink(f);


	//stopping conditions
	if( stoppingConditionMet( oldFs ) ) return 0;
	else NelderMead(f);
	

}
void initVerts(vector<double> xi, double(*f)(vector<double>) ){
	vertex* vx = new vertex(xi.size(), f(xi), xi);
	v.push_back(vx);
}
//on 2d case more init
void init(double x1, double y1, double x2, double y2, double x3, double y3, double(*f)(vector<double>)){
	v.clear();
	vector<double> v1;
	vector<double> v2;
	vector<double> v3;
	v1.push_back(x1);
	v1.push_back(y1);
	v2.push_back(x2);
	v2.push_back(y2);
	v3.push_back(x3);
	v3.push_back(y3);
	initVerts(v1,f);
	initVerts(v2,f);
	initVerts(v3,f);
}
//4d case for chisq
void init4(double Vo1, double A1, double w1, double phi1,
		double Vo2, double A2, double w2, double phi2,
		double Vo3, double A3, double w3, double phi3,
		double Vo4, double A4, double w4, double phi4,
		double Vo5, double A5, double w5, double phi5,
		double (*f)(vector<double>)){
	v.clear();
	vector<double> v1;
	vector<double> v2;
	vector<double> v3;
	vector<double> v4;
	vector<double> v5;
	v1.push_back(Vo1);
	v1.push_back(A1);
	v1.push_back(w1);
	v1.push_back(phi1);
	v2.push_back(Vo2);
	v2.push_back(A2);
	v2.push_back(w2);
	v2.push_back(phi2);
	v3.push_back(Vo3);
	v3.push_back(A3);
	v3.push_back(w3);
	v3.push_back(phi3);
	v4.push_back(Vo4);
	v4.push_back(A4);
	v4.push_back(w4);
	v4.push_back(phi4);
	v5.push_back(Vo5);
	v5.push_back(A5);
	v5.push_back(w5);
	v5.push_back(phi5);
	initVerts(v1,f);
	initVerts(v2,f);
	initVerts(v3,f);
	initVerts(v4,f);
	initVerts(v5,f);
} 
void print(){
	for(int i=0; i<v.size(); i++){
		cout<<"points ";
		for(int j=0; j<v[0]->getxi().size(); j++){
			cout<<v[i]->getxi()[j]<<" ";
		}
		cout<<"value "<<v[i]->getf()<<endl;
	}
}
int main(){

	//debug test with test function, find the bottom of the bowl
	//make three vertices
	/*
	init(10,20,-10,-20,15,15,testfunc);
	NelderMead(testfunc);
	print();
	*/
	
// #1 (a)
	cout<<"1(a)------------------"<<endl;
	init(-1.2,1.0,-2,1,1,0,func1);
	NelderMead(func1);
	print();
	cout<<"---------------------"<<endl;

// #1(b)
	cout<<"1(b)------------------"<<endl;
	cout<<"minima1"<<endl;
	init(-1.2,-1.2,-1.1,-1.1,-1.3,-1.3,func2);
	NelderMead(func2);
	print();
	cout<<"minima2"<<endl;
	init(1,-1, 1,-1.3,1,-0.9,func2);
	NelderMead(func2);
	print();
	cout<<"minima3"<<endl;
	init(3,1,3.2,0.9,2.9,1.0,func2);
	NelderMead(func2);
	print();
	cout<<"minima4"<<endl;
	init(0,0,0.1,0.2,0.5,1,func2);
	NelderMead(func2);
	print();
	cout<<"---------------------"<<endl;
//#2 use nelder mead to minimize chi^2 for each datapoint,
	
	fileio* f = new fileio("measurements2.dat");
	x = f->x;
	y = f->y;
	sig = f->sigma;
	init4(3,0.4,6,10, 2.5,0.5,7,9, 3.1,0.5,4,5, 3.5,0.3,12,10, 3,0.6,8,12, func3);
	NelderMead(func3);
	cout<<"#2 chisq 4parameter fit Vo + Asin(wx - phi)"<<endl;
	print();
	
}


