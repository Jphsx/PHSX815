#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double func1(double x){
return atan(x*x - x + 1);
}
double threeptL(double(*f)(double), double a,double h){
return (1/(2*h))*(-3*f(a) + 4*f(a+h) - f(a+2*h));
}
double threeptC(double(*f)(double), double a,double h){
return (1/(2*h))*(f(a+h) - f(a-h) );
}
double threeptsecond(double(*f)(double), double a, double h){
return (1/(h*h))*(f(a+h)- 2*f(a) + f(a-h));
}
int main(){
	double a=1;
	double h[5]={0.1, 0.1/2, 0.1/(2*2), 0.1/(2*2*2), 0.1/(2*2*2*2)};
	
	cout<<setprecision(9);
	
	cout<<"PROBLEM 1----------------------------"<<endl;
	for(int i=0; i<5; i++){
		cout<<"APPROXIMATION "<<"P_2("<< a <<", "<<h[i]<<")= "<< threeptL(func1,a,h[i])<<endl;

		cout<<"ABSOLUTE ERROR "<<"|P_2("<< a <<", "<<h[i]<<") - f'(1)| = "<< abs(threeptL(func1,a,h[i])-0.5)<<endl;
		
		cout<<"APPROXIMATE ERROR "<< ((h[i]*h[i])/3 )*2.5<<endl;
		cout<<endl;
		
	}
	//send h-> -h
	for(int i=0; i<5; i++){
		h[i] = -1*h[i];
	}
		cout<<"PROBLEM 2----------------------------"<<endl;
	for(int i=0; i<5; i++){
		cout<<"APPROXIMATION "<<"P_2("<< a <<", "<<h[i]<<")= "<< threeptL(func1,a,h[i])<<endl;

		cout<<"ABSOLUTE ERROR "<<"|P_2("<< a <<", "<<h[i]<<") - f'(1)| = "<< abs(threeptL(func1,a,h[i])-0.5)<<endl;
		
		cout<<"APPROXIMATE ERROR "<< ((h[i]*h[i])/3 )*2.5<<endl;
		cout<<endl;
		
	}
	//send h back to +h
	for(int i=0; i<5; i++){
		h[i] = -1*h[i];
	}
		cout<<"PROBLEM 3----------------------------"<<endl;
	for(int i=0; i<5; i++){
		cout<<"APPROXIMATION "<<"P_2("<< a <<", "<<h[i]<<")= "<< threeptC(func1,a,h[i])<<endl;

		cout<<"ABSOLUTE ERROR "<<"|P_2("<< a <<", "<<h[i]<<") - f'(1)| = "<< abs(threeptC(func1,a,h[i])-0.5)<<endl;
		
		cout<<"APPROXIMATE ERROR "<< ((h[i]*h[i])/6 )*2.5<<endl;
		cout<<endl;
		
	}
	cout<<setprecision(12);
	double h1[6] = {0.1, 0.1/2, 0.1/(2*2), 0.1/(2*2*2), 0.1/(2*2*2*2), 0.1/(2*2*2*2*2)};
	
		cout<<"PROBLEM 4----------------------------"<<endl;
	for(int i=0; i<6; i++){
		cout<<"APPROXIMATION "<<"P_2("<< a <<", "<<h1[i]<<")= "<< threeptsecond(func1,a,h1[i])<<endl;

		cout<<"ABSOLUTE ERROR "<<"|P_2("<< a <<", "<<h1[i]<<") - f'(1)| = "<< abs(threeptsecond(func1,a,h1[i])-0.5)<<endl;
		
	
		cout<<endl;
	}
}	
