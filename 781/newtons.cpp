#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
double func1(double x){
	return -(x*x*x)-cos(x);
}
double dfunc1(double x){
	return -3*(x*x)+sin(x);
}
double func2(double x){
	return 3*(x+1)*(x-0.5)*(x-1);
}
double dfunc2(double x){
	return 9*(x*x - 3*x - 3);
}
double func3(double x){
	return x*x*x - 3;
}
double dfunc3(double x){
	return 3*x*x;
}
double func4(double x){
	return x*x*x*x*x + 2*x + 3;
}
double dfunc4(double x){
	return 5*x*x*x*x + 2; 
}
double newton(double(*f)(double),double(*df)(double), double pOLD, double TOL, int N){
	int n=1;
	double p;
	while (n<=N){
		p = pOLD - f(pOLD)/df(pOLD);
		cout<<setprecision(15);
		cout<<"p"<<n<<" "<<p<<endl;
		if( abs(p-pOLD) < TOL ){
			return p;
		}
		n++;
		pOLD = p;
	}
	return p;
}
int main(){
	/*double p0 = -1;
	
	//hw 4b #1
	cout<<"-x^3 - cos(x)"<<endl;
	double zero = newton(func1,dfunc1,p0,1e-15,4);
	cout<<setprecision(15);
	cout<<"zero "<<zero<<endl;
	
	//hw 4b #3
	cout<<"3*(x+1)*(x-0.5)*(x-1)"<<endl;
	//we know one zero is p=1/2;
	//p0 must be selected such that |1/2 - p0| >10^-1
	p0= (0.5) - (1.1e-1);
	cout<<p0<<endl;
	zero = newton(func2,dfunc2,p0,1e-4,10000);
	cout<<"zero "<<zero<<endl;

	/*double P=-100;
	while(P<100){  // note had the f'(x) wrong so wouldnt converge correctly
	//lets find that p0 the easy way
		zero=newton(func2,dfunc2,P,1e-4,100);
		if( abs((zero - (1/2))) < 1e-4 ){
			cout<<"found a p0 "<< p0<<endl;
			cout<<"converged to zero "<<zero<<endl;
		}
		P=P+0.000001;
	}*/
	//EXAM1 #3c
	/*cout<<endl<<endl;
	p0 = 1.2;
	zero = newton(func3, dfunc3, p0,1e-3,1000);
	cout<<"zero "<<zero<<endl;*/

//final exam 
	double p0=-2;
	double zero = newton(func4, dfunc4, p0, 1e-3, 1000);
	cout<<"zero "<<zero<<endl;
}
