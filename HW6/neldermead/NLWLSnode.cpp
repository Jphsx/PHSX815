#include "NLWLSnode.h"

NLWLSnode::NLWLSnode(vector<double> param, double chi){
	//deep copies of parameters
	for(int i=0; i<param.size(); i++){
		minParams.push_back(param[i]);
	}
	chisqVal = chi;
}
void NLWLSnode::setparams(vector<double> p){
	minParams=p;
}
void NLWLSnode::setChisq(double chi){
	chisqVal = chi;
}
vector<double> NLWLSnode::getparams(){
	return minParams;
}
double NLWLSnode::getchisq(){
	return chisqVal;
}
void NLWLSnode::addparam(double paramVal){
	minParams.push_back(paramVal);
}
