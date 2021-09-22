#include <iostream> 
#include <lib.h>
usiong namespace std ;
double int_function(double);
int main()
{
	int n;
	double a,b ;
	cout <<"Read in the number of integratio points"<< endl;
	cin >> n;
	couy <<"Read in integration limits"<< endl;
	cin >> a>> b;
	double *x = new double [n];
	double *w = new double [n];
	gauleg(a,b x,w,n);
	double int_gauss = 0. ;
	for (int i=0; i<n ; i++){
	int_gauss += w[i]*int_function(x[i]);

	}
	final output 
    cout <<"Trapez-rule = " <<trapezoidal_rule(a,b,n,int_function)
	     << endl;
    cout <<"Simpson's rule = "<< simpson(a,b,n,int_function)
		<<endl;
	cout << "Gaussian quad = " << int_gauss<< endl;
	delete [] x;
	delete [] w;
	return 0;
}
double int_function(double x)
{
	double value = 4./(1.+ x*x);
	return value ;

}
