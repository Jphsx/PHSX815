#ifndef _CITY_
#define _CITY_
using namespace std;
class city{

	public:
		city(double x, double y);
		//~city();
		double getX();
		double getY();
		void setX(double x);
		void setY(double y);
	
	private:
		double X;
		double Y;
		//double cityNum;
};

#endif
