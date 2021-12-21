#include<iostream>
using namespace std;
#include<stdlib.h>

class Um1D
{
 public:
  double x00, delt,vx,time;
  int steps;
  Um1D(double x0,double dt,double vx0,double ttot);
  ~Um1D(void);
  double x(double tt);
  void archive();
};
Um1D::Um1D(double x0,double dt,double vx0,double ttot){
    x00 = x0;
    delt =dt;
    vx = vx0;
    time = ttot;
    steps = ttot/delt;
}
Um1D::~Um1D(void){
    printf("Class Um1D destroyed \n");
}
double Um1D::x(double tt){
    return x00+tt*vx;
}
void Um1D::archive(){
    FILE *pf;
    int i ;
    double xx,tt;
    if((pf=fopen("Mition1D.dat","w+"))==NULL){
        printf("Could not open file\n");
        exit(1);     
    }
    tt=0.0;
    for(int i=1;i<=steps;i++){
        fprintf(pf,"%f %f\n",tt,xx);
        tt = tt+delt;
    }
    fclose(pf);
}
int main(){
    double inix, inivx, dtim, ttotal;
    inix=5.0;
    dtim = 0.1;
    inivx = 10.0;
    ttotal = 4.0;
    Um1D unimotx(inix, dtim,inivx,ttotal);
    unimotx.archive();
}