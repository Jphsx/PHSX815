#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;
double function(double tj, double yj, double lam){
	return lam*yj + (1-lam)*cos(tj) - (1+lam)*sin(tj);
}
double f2(double tj){
	return cos(tj) + sin(tj);
}
double euler(double y0, double h,int n){
	int i = 0;
	double value = y0;
	cout<<value<<endl;
	for(int j=0; j<n; j++){
	 value = value + h*function(j*h,value,-100);
	cout<<value<<endl;

	}
}
int main(){

	double h = 0.25;
	double y0 = 1;
	double t0 = 0 +(0)*h;
	double t1 = 0 +(1)*h;
	double t2 = 0 + (2)*h;
	double t3 = 0 + (3)*h;
	double t4 = 0 + (4)*h;
	double lamda1 = -100;
	//double y1;
	

	double initialguess = y0 + 0.25*function(t0,y0,lamda1);
	
//double tj;
//double y1;;
//double yj =y0;
//double trueY;
//	cout<<initialguess<<endl;
//	cout<<"t "<<t1<<endl;
//	y1 = y0 + 0.25*function(t1,initialguess, lamda1);
//	cout<<y1<<endl;	
	
	/*for(int j=1; j<2; j++){
		//tj = ((double)j+1)*0.25;
		//cout<<"tj "<<tj<<endl;
		yjp1 = y0 + 0.25*function(t0,initialguess, lamda1);
		//yj = yjp1;
		
		cout<<yjp1<<endl;
		trueY = f2(t1);
		cout<<"actual "<<trueY<<endl;
	}*/	
	
//////TRapezoidal
	euler(1,0.25,5);
	//double y0p1 = 
	//double y1 = y0 + (h/2)*(function(t0,y0,lamda1) + function(t1,y1
	
}
