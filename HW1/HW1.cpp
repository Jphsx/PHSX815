
#include <iomanip>
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
typedef vector< vector<double> > Matrix;

template<class type>
type GetUnitRoundoff(type number){
	type a=number;
	type b=number;
	while(1){
		if(a-b == a) return b;
		else{
			b=b-b/10.0; 	
		}
	}
}
template<class type>
type Simpson(type(*f)(type), type a, type b, type h){
	return /*((b-a)/2)*/ h * ((1/3)*f(a) + (4/3)*f((b-a)/2) + (1/3)*f(b));
}
template<class type>
type Simpson38(type(*f)(type), type a, type b){
	double x[4];
	double h = (b-a)/3;
	for(int j=0; j<4; j++){
		x[j] = a + j*h;
	}	
	return h * ( (3/8)*f(x[0]) + (9/8)*f(x[1]) + (9/8)*f(x[2]) + (3/8)*f(x[3]) );
}
template<class type>
type hw1function(type x){
	return x*x*x*cos(x);
}
//reads matrix dimensions from file
int* getMatrixDim(const char * filepath){
	
	ifstream f1(filepath);
	int dim[1]; //{rows,columns}
	dim[0]=0; dim[1]=0;
	string str;
	double a;
	vector<double> elements;

	while (f1>>a){
       		 elements.push_back(a);
   	}
	f1.close();

	ifstream f2(filepath);
	while ( getline(f2,str) ) {
		dim[0]++;
	}
	f2.close();

	dim[1] = elements.size()/dim[0];
	int* ptr = dim;
	return ptr;
}
// (ROW, COLUMN)
Matrix ReadMatrix(const char* filepath){
	int* dim = getMatrixDim(filepath);
	Matrix x(dim[0], vector<double>(dim[1]));
	ifstream f(filepath);
	double temp;
	for(int i=0; i<dim[0];i++){
		for(int j=0; j<dim[1]; j++){
			f>>temp;
			x[i][j] = temp;		
		}
	}
	return x;
}
void PrintMatrix(Matrix matrix){
	
	for(int i=0; i<matrix.size(); i++){
		for(int j=0; j<matrix[i].size() ; j++){
			cout<<matrix[i][j]<< " ";		
		}
		cout<<endl;
	}
	cout<<endl;
}
Matrix MultiplyMatrix(Matrix A, Matrix B){
	Matrix C( A.size(), vector<double>( B[0].size() ) );
	for(int i = 0; i<C.size(); i++){
		for(int j=0; j<C[i].size(); j++){
			for(int k=0; k<B.size();k++){
				C[i][j] += A[i][k] * B[k][j];	
			}
		}
	}
	return C;
}

/*double FindN(double precision, double I,double a,double b){
	double s= 0.0;
	double n = 2;
	double h;
//h = b-a /n 
	while( abs(I-s)/I > precision ){
		s=0.0;
		n= n+2;
		h=(b-a)/n;
		cout<< "n: "<<n<<endl;
		//generate unique nodes x0,...,xn
		double* x = new double[(int)n];
		for(int i = 0; i<n+1 ; i++){
			x[i] = a + i*h;
			cout<<"x"<<i<<": "<<x[i]<<" ";
		}
		
		cout<<endl;		
		int aindex=0;
		int bindex=2;
		for(int j = 0; j<(n/2) ; j++){
			
			s += Simpson(hw1function,x[aindex],x[bindex],h);
			
			cout<<"x"<<aindex<<" "<<x[aindex]<< " "<<"x"<<bindex<<" "<<x[bindex]<<endl;
			aindex=aindex+2;
			bindex=bindex+2;
		}
		cout<<"s: "<<s<<" I: "<<I<<endl;
		delete x;
	}
	cout<<"N simpson precision is "<<abs(I-s)/I <<"with n :"<<n<<endl;
	return n;
}*/
double SimpsonN(double(*f)(double), double a, double b, double n){
	double h = (b-a)/n;
	//make coeffs
	double * coeffs = new double[(int)n];
	coeffs[0] = 1.0/3.0;
	coeffs[(int)n] = 1.0/3.0;
	for(int i=1; i<n-1; i++){
		if(i%2 == 0){//even
			coeffs[i]=2.0/3.0;
		}
		else{//odd
			coeffs[i]=4.0/3.0;
		}
	} 
	double I=0;
	double* x = new double[(int)n];
	for(int i = 0; i<n+1 ; i++){
		x[i] = a + i*h;
		//cout<<"x"<<i<<": "<<x[i]<<" "<<"coeff: "<<coeffs[i]<<" ";
	}
	//cout<<endl;
	for(int i =0; i<n; i++){
		I+=f(x[i])*coeffs[i];
	}
	delete x;
	delete coeffs;
	return I*h;

}
double FindN(double precision, double I,double a,double b){
	double s= 0.0;
	double n = 2;
	double h;
//h = b-a /n 
	while( abs(I-s)/I > precision ){
		s= SimpsonN(hw1function,a,b,n);
		n=n+2;
	}
	cout<<"N simpson precision is "<<abs(I-s)/I <<"with n :"<<n<<endl;
	return n;
}

int main(){

	cout<<setprecision(15);
	//#1
	/* The unit roundoff for float 32bit is 10^-6, the unit roundoff for double precision  10^-15
		to get unit roundoff, subtract a small number from another number, when the difference = 0 that is roundoff
	*/
	float a=1.0;
	double b=1.0;
	cout<<"Unit Roundoff Single Precision "<<GetUnitRoundoff(a)<<endl<<"Unit Roundoff Double Precision "<<GetUnitRoundoff(b)<<endl;
	//////////////////

	//#2
	/* from 0 to 1 I(x^3 cos x dx) = 6-5sin1 - 3cos1= 0.171738158 check versus simpsons rule	
	*/
	double I = 0.171738158;
	double S = Simpson(hw1function, 0.0,1.0,(b-a)/2);
	//cout<< "exact: "<<I << " approximation S: "<< S <<endl << "|I-s|= "<<I-S<< endl << "|I-s|/I = "<< (I-S)/I<<endl;
	double S38 = Simpson38(hw1function,0.0,1.0);
	//cout<< "exact: "<<I << " approximation S38: "<< S38 <<endl << "|I-s38|= "<<I-S38<< endl << "|I-s38|/I = "<< (I-S38)/I<<endl;
	/////////////////

	double N = FindN(0.1,I,0.0,1.0);
	N = FindN(0.01,I,0.0,1.0);
	N = FindN(0.001,I,0.0,1.0);
	N = FindN(0.0001,I,0.0,1.0);

	//#3
	/*Read in matrices and do matrix operations
	*/
	Matrix A = ReadMatrix("amatrix.txt");
	PrintMatrix(A);
	Matrix B = ReadMatrix("bmatrix.txt");
	PrintMatrix(B);
	Matrix C = MultiplyMatrix(A,B);
	cout<<"A * B"<<endl;
	PrintMatrix(C);
	cout<<"B * A"<<endl;
	Matrix D = MultiplyMatrix(B,A);
	PrintMatrix(D);
	
}
	
