#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;
/*double f1(double t, double y){

	return (1/(1+t*t)) - 2*y*y;
}
double F1(double t){
	return t/(1+t*t);
}*/
double f1(double t, double y){
	return (-100*y) + (101*cos(t)) + (99*sin(t));
}
double F1(double t){
	return sin(t) + cos(t);
}
int main(){

	//problem #2 0<=t<=1
	//function f1
	//y(0) = 0 = y0
	//beta = 1 c = 1/2
	//tj = 0 + jh
	double h = 0.5;

	//first run j= 0,1,2
	double j0,j1,j2,j3,j4,j5;
	j0=0;
	j1=1;
	j2=2;
	double y0,y1,y2,y3,y4,y5;
	double Y0,Y1,Y2,Y3,Y4,Y5;
	double t0,t1,t2,t3,t4,t5;
	double e0,e1,e2,e3,e4,e5;
	t0=j0;
	t1=j1*h;
	t2=j2*h;
	
	y0=0;
	//j = 0
	y1= y0 + h*f1(t0 + (h/2), y0+ (h/2) *f1(t0,y0));

	//j = 1
	y2 = y1 + h*f1(t1 + (h/2), y1 + (h/2) *f1(t1,y1));

	//j = 2
	//y3 = y2 + h*f1(t2 + (h/2), y2 + (h/2) *f1(t2,y2));

	cout<<setprecision(9);
	Y0 = F1(t0);
	Y1 = F1(t1);
	Y2 = F1(t2);
	e0 = y0 - Y0;
	e1 = y1 - Y1;
	e2 = y2 - Y2;
	
	cout<<y0<< " " << Y0 << " " << e0 <<endl;
	cout<<y1<< " " << Y1 << " " << e1 <<endl;
	cout<<y2<< " " << Y2 << " " << e2 <<endl;

	//now j run 0,1,2,3,4,5
	h=0.2;
	j0=0;
	j1=1;
	j2=2;
	j3=3;
	j4=4;
	j5=5;
	t0=j0;
	t1=j1*h;
	t2=j2*h;
	t3=j3*h;
	t4=j4*h;
	t5=j5*h;

	y0=0;
	y1 = y0 + h*f1(t0 + (h/2), y0 + (h/2) *f1(t0,y0));
	y2 = y1 + h*f1(t1 + (h/2), y1 + (h/2) *f1(t1,y1));
	y3 = y2 + h*f1(t2 + (h/2), y2 + (h/2) *f1(t2,y2));
	y4 = y3 + h*f1(t3 + (h/2), y3 + (h/2) *f1(t3,y3));
	y5 = y4 + h*f1(t4 + (h/2), y4 + (h/2) *f1(t4,y4));

	Y0 = F1(t0);
	Y1 = F1(t1);
	Y2 = F1(t2);
	Y3 = F1(t3);
	Y4 = F1(t4);
	Y5 = F1(t5);
	
	e0 = y0 - Y0;
	e1 = y1 - Y1;
	e2 = y2 - Y2;
	e3 = y3 - Y3;
	e4 = y4 - Y4;
	e5 = y5 - Y5;
	
	cout<<y0<< " " << Y0 << " " << e0 <<endl;
	cout<<y1<< " " << Y1 << " " << e1 <<endl;
	cout<<y2<< " " << Y2 << " " << e2 <<endl;
	cout<<y3<< " " << Y3 << " " << e3 <<endl;
	cout<<y4<< " " << Y4 << " " << e4 <<endl;
	cout<<y5<< " " << Y5 << " " << e5 <<endl;


	//////////// number 3
	h=0.25;
	double j[(int)(1/h + 1)];
	for(int i=0; i<(1/h + 1);i++){
		j[i] = i;
		cout<<"j"<<i<<" = "<< i<<endl;
	}
	double t[(int)(1/h + 1)];
	for(int i=0; i<(1/h + 1); i++){
		t[i] = j[i]*h;
		cout<<"t"<<j[i]<< " = "<< t[i]<<endl;
	}
	double e[(int)(1/h + 1)];
	double y[(int)(1/h + 1)];
	y[0] = 0; //this value is for # 2,3
	y[0] = 1; //this value is for # 4,5
	double Y[(int)(1/h + 1)];

	//2nd order runge kutta
	/*for(int i=0; i<(1/h + 1); i++){
		y[i+1] = y[i] + (h/4)*( f1(t[i],y[i]) + 3*f1(t[i] + ((2*h)/3) , y[i] + ((2*h)/3)*f1(t[i],y[i])));
	}*/

	double k1,k2,k3,k4;
	//4th order runge-kutta
	for(int i=0; i<(1/h + 1);i++){
		k1 = f1(t[i],y[i]);
		k2 = f1(t[i] + (h/2), y[i] + (h/2)*k1);
		k3 = f1(t[i] + (h/2), y[i] + (h/2)*k2);
		k4 = f1(t[i+1], y[i] + h*k3);
		y[i+1] = y[i] + (h/6)*(k1 + 2*k2 + 2*k3 + k4);
	}
	
	for(int i=0; i<(1/h + 1); i++){
		Y[i] = F1(t[i]);
	}
	for(int i=0; i<(1/h + 1); i++){
		e[i] = y[i] - Y[i];
	}
	for(int i=0; i<(1/h + 1); i++){
		cout<< y[i] <<" "<< Y[i] << " "<< e[i]<< endl;
	}
}
