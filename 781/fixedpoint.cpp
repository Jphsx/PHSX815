#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;
double p;
int n = 1;
const double pi = 3.14159;

double lam = -100;
double tjp1 = 0.25;

double function1(double x){
	return pi + 0.5*sin(x/2) ;
}
double function1_prime(double x){
	return 0.25*cos(x/2);
}
double function2(double x){
	return x/2 + 1/x;
}
double function3(double x){
	return 3/(x*x*x*x) - 1/x + x;
}
double fdif1( double x){
	double yj=1;
	double h=0.25;
	 //lam = -100;
	//doubl tjp1 = 0.25;
	return yj + h*(lam*x + (1-lam)*cos(tjp1) - (1+lam)*sin(tjp1)) ;
}
void fixedpoint(double(*f)(double), double pOLD,double TOL, int N){
	
	p = f(pOLD);
	std::cout<<"p_"<<n<<" "<<p<<std::endl;
	if( std::abs(p-pOLD)<TOL) return;
	if(n>N) return;
	n++;
	fixedpoint(f,p,TOL,N);
	return;
}
void print(){
	std::cout<<std::setprecision(15);
	std::cout<<"p "<<p<<" n "<<n<<std::endl;
}
int main(){
	double p0;
	//HW3b #1
	//fixedpoint(function1,2,10e-2,1000);
	//print();

	//HW3b #2
	/*fixedpoint(function2,0.1,10e-15,1000);
	print();
	
	fixedpoint(function2,-0.1,10e-15,1000);
	print();
	std::cout<<std::endl;
	std::cout<<"calculations "<<std::endl;
	std::cout<<"g(p) "<<function1(3.63057)<<std::endl;
	std::cout<<"g(p0) "<<function1(2)<<std::endl;
	
	p0=function1(2);
	double P=3.63057;
	double top= std::log( std::abs((function1(P)- function1(p0)))/(4-p0) );
	double bottom = std::log( std::abs(function1_prime(p0)) );
	std::cout<<"n "<< top/bottom<<std::endl;
	*/
	//Exam1 #3d
	//cout<<endl;
	//cout<<"exam ?"<<endl;
	//fixedpoint(function3,1.2,1e-3,1000);
	//print();
	double yj=1;
	double h=0.25;
	//double lam = -100;
	double t0 = 0;
	double guess = yj + h*(lam*yj + (1-lam)*cos(t0) - (1+lam)*sin(t0));
	cout<<"guess "<<guess<<endl;
	cout<<"esitmate y1: "<<endl;
	fixedpoint(fdif1,1,1e-3,10); 
		
}
