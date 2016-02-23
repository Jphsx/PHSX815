#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

//returns 1 for (+) and -1 for (-) returns 0 if a parameter is 0
double sign(double param){
	std::cout<<"param :"<<param<<std::endl;	
	if(param<0.0) return -1;
	if(param>0.0) return 1;
	if(param == 0) return 0;
	
}
double function1(double x){
	return 3*(x+1)*(x-0.5)*(x-1);
}
double function2(double x){
	return x*x - 2;
}
double function3(double x){
	return x*x*x + x - 4;
}
double function4(double x){
	return x*x*x -x - 1;
}
double function5(double x){
	return tan(x)-x;
}
double function6(double x){
	return x*x*x - 3;
}
double function7(double x){
	return x*x*x*x*x + 2*x + 3;
}
double bisection(double(*f)(double), double a, double b, double TOL, int N ){
	int n = 1;
	double sign_fa = sign( f(a) );

	double halfLength, p, sign_fp;
	
	while( n <= N ){
		 halfLength = (b-a)/2.0;
		 p = a + halfLength;
		std::cout<<std::setprecision(15);
		std::cout<<"p_"<<n<<" = "<< p<<"  hl: "<<halfLength<<std::endl;
		if(halfLength < TOL) return p;
		
		n++;
		sign_fp = sign( f(p) );
		if(sign_fp == 0.0) return p;
		if(sign_fp*sign_fa > 0) a=p;
		if(sign_fp*sign_fa < 0) b=p;
		
	}
	std::cout<<"iterated over all N N="<<N<<std::endl;
	return p;
}
int main(){
	std::cout<<std::setprecision(15);
	double zero;
	/*//HW 3a #1a
	std::cout<<"3(x+1)(x-0.5)(x-1)"<<std::endl;
	double zero = bisection(function1,-2,1.5,10e-15,4);
	std::cout<<zero<<std::endl;	
	std::cout<<"============================"<<std::endl;

	//HW 3a #1b
	std::cout<<"3(x+1)(x-0.5)(x-1)"<<std::endl;
	zero = bisection(function1, -1.25,2.5,10e-15,4);
	std::cout<<zero<<std::endl;
	std::cout<<"============================"<<std::endl;

	//HW 3a #2
	std::cout<<"x^2 -2"<<std::endl;
	zero = bisection(function2, 1.40,1.42,10e-15,4);
	std::cout<<zero<<std::endl;
	std::cout<<"============================"<<std::endl;

	//HW 3a #3a
	std::cout<<"x^3 +x-4"<<std::endl;
	zero = bisection(function3, 1,4,10e-3,1000);
	std::cout<<zero<<std::endl;
	std::cout<<"============================"<<std::endl;
	
	//HW 3a #3b
	std::cout<<"x^3-x-1"<<std::endl;
	zero = bisection(function4, 1,2,10e-3,1000);
	std::cout<<zero<<std::endl;
	std::cout<<"============================"<<std::endl;

	//HW 3a #4a
	std::cout<<"tan(x)-x"<<std::endl;
	zero = bisection(function5,1,2,10e-4,10000);
	std::cout<<zero<<std::endl;
	std::cout<<"============================"<<std::endl;
	
	//HW 3a #4b
	//the good values are 98.95004,98.5007
	std::cout<<"tan(x)-x"<<std::endl;
	zero = bisection(function5, 98.95,98.959,10e-4,10000);
	std::cout<<zero<<std::endl;
	std::cout<<"f(p)="<<function5(zero)<<std::endl;
	std::cout<<"============================"<<std::endl;

	//EXAM1 #3
	std::cout<<"x^3 - 3"<<std::endl;
	zero = bisection(function6,1.2,1.6,1e-3,1000);
	cout<<zero<<endl;
	cout<<"f(p)="<<function6(zero)<<std::endl;
	std::cout<<"============================"<<std::endl; */

	//Final exam
	std::cout<<"x^5 + 2x + 3"<<std::endl;
	zero = bisection(function7,-2,0,1e-3,1000);
	cout<<zero<<endl;
	cout<<"f(p)="<<function7(zero)<<std::endl;
	std::cout<<"============================"<<std::endl; 
}
