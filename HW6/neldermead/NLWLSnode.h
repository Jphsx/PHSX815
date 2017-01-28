#include <vector>
using namespace std;
//each node will be minimized for a given datapoint and uncertainty,
//this should yield the chisq contour space when all nodes are minimized
//global minimum of that contour should be the optimal parameters
class NLWLSnode{
	
	
	public:
		NLWLSnode(vector<double> param, double chi);
		void setparams(vector<double> p);
		void setChisq(double chi);
		vector<double> getparams();
		double getchisq();
		void addparam(double paramVal);

	private:
		vector<double> minParams;
		double chisqVal;


};
