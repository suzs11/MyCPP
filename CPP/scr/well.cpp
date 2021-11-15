// ===========================================================
// f i l e : well . cpp
//
// Computation of energy eigenvalues and eigenfunctions
// of a p a r t i c l e in an i n f i n i t e well with V(−x )=V( x )
//
// Input : energy : i n i t i a l guess for energy
// p a r i t y : desired p a r i t y of sol uti on (+/− 1)
// Nx−1 : Number of RK4 steps from x=0 to x=1
// Output : energy : energy eigenvalue
// psi . dat : f i n a l psi [ x ]
// a l l . dat : a l l psi [ x ] for t r i a l energies
// ===========================================================
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include<cmath>
using namespace std ;
//−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
const int P = 10000;
double energy ;
//−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
void
RKSTEP ( double& t,double& x1,double& x2,const double& dt ) ;
//−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
int main(){
double dx , x , epsilon , de ;
double psi , psip , psinew , psiold ;
double array_psifinal[2*P+1] , array_xstep[2*P + 1];
double *psifinal = array_psifinal+P ;
double *xstep = array_xstep +P ;
// p s i f i n a l point s to ( a r r a y _ p s i f i n a l +P) and one can
// use p s i f i n a l [−P ] . . . p s i f i n a l [P ] . S im i l a r l y fo r x step
int parity, Nx, iter, i, node ;
string buf;
//−−−−−− Input :
cout<<"Enter energy , pa rity , Nx:\n"<<endl; 
cin >> energy >> parity >> Nx ; getline ( cin , buf);
if(Nx >P){cerr << "Nx>P\n" ;exit(1);}
if (parity>0){parity=1;}
else{parity=-1;}
cout << "# #######################################\n"<<endl ;
cout << "# Estart= "<< energy
<< "parity="<< parity << endl ;
dx = 1.0/(Nx-1) ;
epsilon=1.0e-6;
cout << "# Nx="<< Nx << "dx = "<< dx
<< "eps= "<< epsilon << endl ;
cout << "# #######################################\n"<<endl;
//−−−−−− Calculate :
ofstream myfile ("all.dat") ;
myfile.precision (17) ;
cout.precision (17) ;
iter = 0;
psiold = 0.0;
psinew = 1.0 ;
de = 0.1*abs(energy) ;
while(iter <10000){
// Initial conditions at x=0
x = 0.0;
if ( parity == 1) {
psi = 1.0 ;
psip = 0.0;
} else {
psi = 0.0;
psip = 1.0 ;
}
myfile << iter <<" "<< energy <<" "
<< x << " " << psi << " "
<< psip << endl ;
// Use Runge−Kutta to forward to x=1
for (i=2;i<=Nx;i++){
x = (i-2)*dx;
RKSTEP(x,psi,psip,dx );
myfile << iter << " "<< energy << " "
<< x <<" "<< psi << " "
<< psip << endl ;
}
psinew = psi ;
cout << iter << " " << energy << " "
<< de <<" "<< psinew << endl ;
// Stop i f value of psi c l o s e to 0
if (abs(psinew) <= epsilon) {break;} 
// Change direction of energy search :
if (psinew*psiold < 0.0 ) {de = -0.5*de;
energy += de ;
psiold = psinew ;
iter++;
} // while ( iter < 10000)
myfile.close() ;
//We found the solution :
// calculateit once again and s t o r e i t
if (parity == 1) {
psi = 1.0 ;
psip = 0.0;
node = 0; // count number of nodes of fun ction
} else {
psi = 0.0;
psip = 1.0 ;
node = 1;
}
x= 0.0;
xstep[0] = x ;
psifinal[0] = psi ; // a r ray th at s t o r e s p si ( x )
psiold = 0.0;
// Use Runge−Kutta to move to x=1
for ( i=2 ; i<=Nx ; i++ ){
x = (i-2)* dx ;
RKSTEP (x , psi , psip , dx ) ;
xstep[ i-1] = x ;
psifinal[ i-1] = psi ;
// Use parity to compute psi (−x )
xstep[1-i] = -x ;
psifinal[1-i] = psi * parity ;
// Determine zeroes of psi ( x ) :
// psi should not be zero within epsilon :
if ( abs(psi) > 2.0* epsilon){
if ( psi * psiold < 0.0) {node += 2;
psiold = psi ;
}
} // for ( i =2; i <=Nx; i ++)
node++;
// print final solution :
myfile.open ("psi.dat") ;
cout << "Final result : E= " << energy
<< "n="  << node
<< " parity= " << parity << endl ;
myfile << "# E=" << energy
<< "n=" << node
<< "parity= "<< parity << endl ;
for ( i=-(Nx-1);i<=(Nx-1);i++)
{myfile << xstep [ i ] << " "
<< psifinal[i] << endl;
myfile.close();
}// main()