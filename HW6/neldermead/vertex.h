#include <vector>
using namespace std;

class vertex{
	public:
		vertex();
		vertex(int dimension);
		vertex(int dimension, double functionValue, vector<double> xpoints);
		
		void setdim(int dimension);
		void setf(double functionValue);
		void setxi(vector<double> xpoints);

		int getdim();
		double getf() const;
		vector<double> getxi();
	private:
		int dim;
		double f;
		vector<double> xi;	

};
