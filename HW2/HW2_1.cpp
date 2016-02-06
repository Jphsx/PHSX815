#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;
//GLOBAL variables for Func1 i.e. initial conditions for better abstraction with RK4 and Euler
//initial mass, length, and gravity for pendulum
double m,l,g;

//

//first of coupled ODEs ( d^2 theta / dt^2 ) = -g/l sin(theta)
double Func1(double theta, double temp ){
	return -(g/l)*sin(theta);
}
//second of coupled ODEs (dtheta/dt) = omega
double Func2(double omega){
	return omega;
}
double Func3(double theta,double omega ){
	return -(g/l)*sin(theta) -0.01*omega;
}
//generates y1_n+1 and y2_n+1 ( y1=theta, y2=omega) by 4th order Runge-Kutta method with 2 coupled ODEs and step dt
//uses function pointers for set of ODEs f1 is func1, f2 is func2
double* RK4( double y1, double y2, double dt, double(*f1)(double,double), double(*f2)(double)){
	double k1,k2,k3,k4,l1,l2,l3,l4;

	k1 = dt * f1(y1, y2);
	l1 = dt * f2(y2);
	//l1 = dt * k1;
	//cout<<k1<<" "<<l1<<endl;

	k2 = dt * f1(y1 + l1/2, y2);
	l2 = dt * f2(y2 + k1/2);
	//l2 = dt * k2;
	//cout<<k2<<" "<<l2<<endl;

	k3 = dt * f1(y1 + l2/2, y2);
	l3 = dt * f2(y2 + k2/2);
	//l3 = dt * k3;
	//cout<<k3<<" "<<l3<<endl;

	k4 = dt * f1(y1 + l3/2, y2);
	l4 = dt * f2(y2 + k3/2);
	//l4 = dt * k4;
	//cout<<k4<<" "<<l4<<endl;
	
	//returns the estimations of coupled ODE in a double array of size 2 [y1_n+1, y2_n+1]
	double* y = new double[2];
	y[1] = y2 + (1.0/6.0)*(k1 + 2.0*k2 + 2.0*k3 + k4);
	y[0] = y1 + (1.0/6.0)*(l1 + 2.0*l2 + 2.0*l3 + l4);
	//cout<<y[1]<< " "<<y[0]<<endl;
	return y;
}
double * Euler( double y1, double y2, double dt, double(*f1)(double,double), double(*f2)(double)){
	double* y = new double[2];
	y[1] = y2 + dt*f1(y1,y2);
	y[0] = y1 + y[1]*dt;
	return y;
}
//generates dataset with given intital conditions and writes to file
//boolean arg, false to suppress cout (debugging)
void generateSequence(bool toScreen, double y1, double y2, double dt, int N, double(*f1)(double,double), double(*f2)(double),
	double*(*method)(double, double, double, double (*)(double,double), double (*)(double)), const char* path ){

	ofstream file;
	file.open(path,std::ofstream::out | std::ofstream::app);
	file<<setprecision(15);
	cout<<setprecision(15);
	//file output format y1 y2 dt t
	
	//assume time always starts at 0
	file<<y1<<" "<<y2<<" "<<dt<<" "<<0.0<<endl;
	if(toScreen) cout<<y1<<" "<<y2<<" "<<dt<<" "<<0.0<<endl;

	double* y = method(y1,y2,dt,f1,f2);
	for(int i = 1; i<N; i++){
		file<<y[0]<<" "<<y[1]<<" "<<dt<<" "<<dt*i<<endl;
		if(toScreen) cout<<y[0]<<" "<<y[1]<<" "<<dt<<" "<<dt*i<<endl;
		y = method(y[0],y[1],dt,f1,f2);	
	}

	file.close();
}
void cleanFiles(){
	ofstream file1, file2;
	file1.open("RK4.txt");
	file2.open("Euler.txt");
	file1<<endl;
	file2<<endl;
	file1.close();
	file2.close();		
}

int main(){

	//initial conditions: mass, length, gravity, angular displacement, angular velocity in kg, m, m/s^2, rad, rad/s respectively
	//m,l,g defined globally for Func1, so RK4 is more abstract
	double theta0,omega0;
	m = 1.0;
	l = 2.0;
	g = 9.80;
	theta0 = M_PI/3;
	omega0 = 0.0;
	
	//prep files for every run
	cleanFiles();
	cout<<setprecision(15);
	//undamped runs 10s
	generateSequence(false,theta0,omega0,0.01,(int)(10.0/0.01),Func1,Func2,RK4,"RK4.txt");
	generateSequence(false,theta0,omega0,0.0001,(int)(10.0/0.0001),Func1,Func2,RK4,"RK4.txt");
	generateSequence(false,theta0,omega0,0.01,(int)(10.0/0.01),Func1,Func2,Euler,"Euler.txt");
	generateSequence(false,theta0,omega0,0.0001,15,Func1,Func2,Euler,"Euler.txt");

	//damped runs 10s
	generateSequence(false,theta0,omega0,0.01,(int)(10.0/0.01),Func3,Func2,RK4,"RK4Damp.txt");
	generateSequence(false,theta0,omega0,0.0001,(int)(10.0/0.0001),Func3,Func2,RK4,"RK4Damp.txt");
	generateSequence(false,theta0,omega0,0.01,(int)(10.0/0.01),Func3,Func2,Euler,"EulerDamp.txt");
	generateSequence(false,theta0,omega0,0.0001,(int)(10.0/0.0001),Func3,Func2,Euler,"EulerDamp.txt");


	

}
