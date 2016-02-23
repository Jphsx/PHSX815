

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double func1(double x){
return x*x*exp(-x);
}
double simpson(double(*f)(double), double a, double b){
	double n = 6;
	double h = (b-a)/n;

	double x[7];
	cout<<setprecision(9);
	for(int j=0; j<7; j++){
		x[j] = a + j*h;
		cout<<"x_"<<j<<" = "<<x[j]<<endl;
	}
	double fx[7];
	for(int k=0; k<7; k++){
		fx[k] = f(x[k]);
		cout<<"f(x_k) = "<<fx[k]<<endl;
	}
	
	//now compute the integral
	double integral;
	integral = (h/3) * (fx[0] + 4*fx[1] + 2*fx[2] + 4*fx[3] + 2*fx[4] + 4*fx[5] + fx[6] );
	return integral;
}
double midpoint(double(*f)(double), double a, double b){
	double n =6;
	double h = (b-a)/(n+2);
	
	double x[(int)n+3];
	cout<<setprecision(9);
	for(int j=0 ; j<n+3; j++){
		x[j] = a + (j+1)*h;
		cout<<"x_"<<j<<" = "<<x[j]<<endl;
	
	}

	double fx[(int)n+3];
	for(int k=0; k<n+3; k++){
		fx[k] = f(x[k]);
		cout<<"f(x_k) = "<<fx[k]<<endl;
	}
	double integral;
	integral =2*h * (fx[0] + fx[2] + fx[4] + fx[6]);
	return integral;
}
int main(){

	// Real Value:
	double I = 0.16060279414;
	double approx;
	cout<<setprecision(9);
	approx = simpson(func1, 0,1);
	cout<<"S2(x)= "<<approx<<endl<<endl;
	cout<<"abs error: "<<abs(I - approx)<<endl;


	approx = midpoint(func1, 0,1);
	cout<<"M(x)= "<<approx<<endl<<endl;
	cout<<"abs error: "<<abs(I - approx)<<endl;
}
