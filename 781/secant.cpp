#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

double func1(double x){
	return -(x*x*x) - cos(x);
}
double func2(double x){
	return 3*(x+1)*(x-0.5)*(x-1);
}
double func3(double x){
	return x*x*x - 3;
}
double func4(double x){
	return x*x*x*x*x + 2*x + 3;
}
double secant(double(*f)(double), double p0,double p1, double TOL, int N){
	int n=2;
	double q0 = f(p0);
	double q1 = f(p1);
	double p;

	while(n <= N){
		p = p1- (q1*(p1-p0))/(q1-q0);
		cout<<"p"<<n<<" "<<p<<endl; 
		if (abs(p-p1)<TOL){
			return p;	
		}
		n++;
		p0 = p1;
		p1 = p;
		q0 = q1;
		q1 = f(p);
	}
	return p;
}
int main(){
	/*double p0 =-1;
	double p1 =0;
	//HW 4b #2
	cout<<"-(x*x*x) - cos(x)"<<endl;
	double zero = secant(func1,p0,p1,1e-15,4);
	cout<<"zero "<<zero<<endl;

	//HW 4b #4
	//again selecting p0 p1 to find p=1/2 
	// | 1/2 - p_0,1 | >10^1
	p0 = (0.5) - (1.1e-1);
	p1 = (0.5) - (1.2e-1);
	cout<<p0<<" "<<p1<<endl;
	//iterate p values again to get convergence
	//*cout<<"#3 test for p0,p1 values that converge"<<endl;
	/*double i=-10;
	double j=-10;
	cout<<setprecision(15);
	while(i<10){
		while(j<10){
			zero=secant(func2,i,j,1e-15,10000);
			if(abs(zero - 0.5) <1e-4){
				cout<<setprecision(15);
				cout<<"converged to .5 "<<zero<<" "<<p0<<" "<<p1<<endl;
			}
			//cout<<zero<<" "<<i<<" "<<j<<endl;
			j=j+0.1;
		}
		i=i+0.1;
	}*/
	//the p0,p1 values that work is -0.11, -0.12
	//p0=-0.11;
	//p1=-0.12;
	/*cout<<"3*(x+1)*(x-0.5)*(x-1)"<<endl;
	zero = secant(func2,p0,p1,1e-4,10000);
	cout<<"zero "<<zero<<endl;

	//EXAM1 #3b
	cout<<endl<<endl;
	p0=1.2;
	p1 = 1.6;
	zero = secant(func3,p0,p1,1e-3,10000);
	cout<<"zero "<<zero<<endl;*/
	
	//final exam
	double p0= -2;
	double p1= 0;
	double zero = secant(func4,p0,p1,1e-3,1000);
	cout<<"zero "<<zero<<endl;
	
}
