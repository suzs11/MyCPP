/*
*******************************************************************************
SSDv06.cpp

Solving the compressed sensing problem by Shortest-Solution guided Decimation
(SSD).

This code uses the dual ascent method to update the guidance vector. It is much
faster than the code SSDv04.cpp which uses singular-value decomposition. This
version SSDv06.cpp should be used in practical applications.

The technical details of this algorithm can found in:
Mutian Shen, Pan Zhang, Hai-Jun Zhou,
Compressed sensing by shortest-solution guided decimation,
arXiv:1709.08388 (2017) [under review at IEEE Access].

Log:
17.12.2017: SSDv06.cpp.

PROGRAMMER:
Hai-Jun Zhou
Institute of Theoretical Physics, Chinese Academy of Sciences
Zhong-Guan-Cun East Road 55, Beijing 100190
zhouhj@itp.ac.cn
http://power.itp.ac.cn/~zhouhj/
*******************************************************************************
*/

#include <cmath>
#include <ctime>
#include <exception>
#include <fstream>
#include <iostream>
#include <stack>
#include <string>
#include <valarray>

using namespace std;

struct IID                                                     //int-int-double
{
  int index1;
  int index2;
  double value;
  IID(int, int, double);
};

IID::IID(int i, int j, double v)
{
  index1=i;
  index2=j;
  value=v;
  return;
}

class CompSense
{
public:
  CompSense(int, int, bool&);                                     //constructor
  bool ReadMatrix(string, int);                       //read measurement matrix
  bool Truth(string);                                     //input a signal hhh0
  void DualAscent(int&, double&);     //updating guidance vector by dual ascent
  void Decimation(string, int&, int&);                                    //SSD
  
private:
  int MMM;                                                //number of rows read
  int NNN;                                    //number of columns in matrix DDD
  int actNNN;                  //active number of columns during the decimation
  int maxIter;                        //maximum iteration in dual ascent method
  valarray<double> DDD;               //Measurement matrix (column-first style)
  valarray<double> hhh;                                   //the inferred signal
  valarray<double> hhh0;                                      //the true signal
  valarray<double> bbb;                            //Lagrange multiplier vector
  valarray<double> Overlap;                          //auxiliary overlap vector
  valarray<double> gamma;                                //auxiliary gap vector
  valarray<double> eta;                        //auxiliary vector (=D (DTgamma)
  valarray<double> zzz;                     //observed vector, zzz = DDD * hhh0
  valarray<int> Element;    //auxiliary vector mapping from index to true index
};




int main(int argv, char **argc)
{
  //1.                                   define the compressive sensing problem
  int MMM=200;         //number of rows to be included from sampling matrix
  int NNN=1000;        //number of columns of sampling matrix
  bool succeed=true;
  CompSense instance(MMM, NNN, succeed);
  if(succeed==false) return 1;
  
  //2.           read the measurement matrix (only the first MMM rows are read)
  string matrix="AAA_Gauss_1000_1000.mtx";
  succeed=instance.ReadMatrix(matrix, MMM);
  if(succeed==false) return 1;
    
  //3.                                             read the planted hhh0 vector
  string hhh0file="xxx0_1000_50.dat00";
  succeed=instance.Truth(hhh0file);
  if(succeed==false) return 1;
  
  //4.                            specify the reconstructed solution hhh vector
  string hhhsolutions = "xxx_1000_50.sol00";
  int depth, nonzeroN;
  time_t tstart=time(NULL);
  clock_t ctstart=clock();
  int  leadindex;
  double distance=1;
  while(distance>1.0e-6)
    instance.DualAscent(leadindex, distance);
  cout<<endl;
  instance.Decimation(hhhsolutions, depth, nonzeroN);
  time_t tend=time(NULL);
  clock_t ctend=clock();
  
  //5.                                          record the total computing time
  cout<< "Time used in seconds: "
      << (tend-tstart)  <<'\t'
      << static_cast<double>(ctend-ctstart)/CLOCKS_PER_SEC
      << endl;
  
  return 0;
}




CompSense::CompSense(int m, int n, bool& succeed)
{
  /* maxIter and Convergence both can be adjusted to speed up the algorithm */
  maxIter=10; //maximum round of iteration in dual ascent method
  cout<<"Iteration number in dual ascent is "<<maxIter<<endl;
  MMM=m;
  NNN=n;
  succeed=true;
  if(MMM>NNN)
    {
      cerr<<"Not a compressed sensing matrix.\n";
      succeed=false;
      return;
    }
  try { DDD.resize( MMM*NNN ); } catch(exception)
    {
      cerr<<"DDD construction failed.\n";
      succeed=false;
      return;
    }
  DDD=0;
  try { bbb.resize( MMM); } catch(exception)
    {
      cerr<<"bbb construction failed.\n";
      succeed=false;
      return;
    }
  bbb=0;
  try { zzz.resize( MMM); } catch(exception)
    {
      cerr<<"zzz construction failed.\n";
      succeed=false;
      return;
    }
  zzz=0;
  try { hhh0.resize( NNN ); } catch(exception)
    {
      cerr<<"hhh0 construction failed.\n";
      succeed=false;
      return;
    }
  hhh0=0;
  try { hhh.resize( NNN ); } catch(exception)
    {
      cerr<<"hhh construction failed.\n";
      succeed=false;
      return;
    }
  hhh=0;
  try { gamma.resize( MMM ); } catch(exception)
    {
      cerr<<"gamma construction failed.\n";
      succeed=false;
      return;
    }
  gamma=0;
  try { Element.resize(NNN); } catch(exception)
    {
      cerr<<"Element construction failed.\n";
      succeed=false;
      return;
    }
  for(int n=0; n<NNN; ++n) Element[n]=n;
  actNNN=NNN;
  try { Overlap.resize(NNN); } catch(exception)
    {
      cerr<<"Overlap construction failed.\n";
      succeed=false;
      return;
    }
  Overlap=0;
  try { eta.resize(MMM); } catch(exception)
    {
      cerr<<"eta construction failed.\n";
      succeed=false;
      return;
    }
  eta=0;
  return;
}

bool CompSense::ReadMatrix(string fname, int nrow)
{
  if(nrow !=MMM) nrow=MMM;                                      //read MMM rows
  actNNN=NNN;
  for(int n=0; n<NNN; ++n) Element[n]=n;
  ifstream input(fname.c_str() );
  if( !input.good() )
    {
      cerr<<"Matrix input file probably non-existent.\n";
      return false;
    }
  int Mval, Nval;
  input>>Mval>>Nval;
  if(Mval < MMM || Nval != NNN)
    {
      cerr<<"Matrix  have too few rows or column number not matching.\n";
      input.close();
      return false;
    }
  double val;
  for(int m=0; m<MMM; ++m)                       //only the first MMM rows read
    {
      for(int n=0; n<NNN; ++n)
	{
	  input>>val;
	  DDD[n*MMM+m]=val;
	}
    }
  input.close();
  return true;
}

//                                       read the true (planted) message vector
bool CompSense::Truth(string fname)
{
  ifstream input(fname.c_str());
  if(!input.good() )
    {
      cerr<<"File "<<fname<<" probably non-existent.\n";
      return false;
    }
  int Nval, N1;
  input>>Nval>>N1;
  if(Nval != NNN)
    {
      cerr<<"Number of elements in hhh0 vector does not match.\n";
      input.close();
      return false;
    }
  cout<<"Number of non-zero entries in planted solution is "<<N1<<endl;
  double val;
  for(int n=0; n<NNN; ++n)
    {
      input>>val;
      hhh0[n]=val;
    }
  input.close();
  zzz=0;
  for(int m=0; m<MMM; ++m)
    {
      val=0;
      for(int n=0; n<NNN; ++n)
	val += DDD[n*MMM+m]*hhh0[n];
      zzz[m]=val;
    }
  actNNN=NNN;
  for(int n=0; n<NNN; ++n) Element[n]=n;
  return true;
}

//                                                SSD for solving DDD hhh = zzz
void CompSense::Decimation(string fname, int& depth, int& N1)
{
  hhh=0;                                  //solution initialized to be all-zero
  depth=0;             //depth of decimation (total number of decimation steps)
  N1=0;                       //number of non-zero elements in the solution hhh
  double norm1zzz=0;
  for(int m=0; m<MMM; ++m) norm1zzz += abs(zzz[m]);
  norm1zzz /= MMM;
  stack<IID> BackTracking;
  //(1)                               shortest-solution guided decimation (SSD)
  //ofstream evolfile("evolution.dat00");
  int leadindex;
  double distance;
  while(norm1zzz>1.0e-8 && depth<MMM)
    {
      ++depth;
      cout<<"Step "<<depth<<": ";
      DualAscent(leadindex, distance);
      --actNNN;
      int nnn0=Element[leadindex];
      Element[leadindex]=Element[actNNN];
      Element[actNNN]=nnn0;
      for(int n=0; n<actNNN; ++n) Overlap[n]=0;
      double sumval =0;
      double sumval0=0;
      int position0=leadindex*MMM;
      int position1=actNNN*MMM;
      for(int m=0; m<MMM; ++m)
	{
	  double value=DDD[position0+m];
	  sumval  += zzz[m]*value;
	  sumval0 += pow(value, 2);
	  DDD[position0+m]=DDD[position1+m];
	  DDD[position1+m]=value;
	  for(int n=0; n<actNNN; ++n) Overlap[n] += value*DDD[n*MMM+m];
	}
      sumval /= sumval0;
      hhh[nnn0]=sumval;
      for(int n=0; n<actNNN; ++n)
	{
	  Overlap[n] /= sumval0;
	  BackTracking.push(IID(nnn0, Element[n], -Overlap[n]) );
	}
      norm1zzz=0;
      for(int m=0; m<MMM; ++m)
	{
	  double value=DDD[position1+m];
	  for(int n=0; n<actNNN; ++n)
	    {
	      position0=n*MMM+m;
	      DDD[position0] -= value*Overlap[n];
	    }
	  zzz[m] -= value*sumval;
	  norm1zzz += abs(zzz[m]);
	}
      norm1zzz /= MMM;
      cout<<"    "<< nnn0 <<"    "<<norm1zzz<<endl;
      /*
      evolfile << depth << '\t' << nnn0 << '\t'
	       << hhh0[nnn0]<< '\t' << abs(hhh0[nnn0])
	       << '\t'<<norm1zzz<<endl;
      */
    }
  //evolfile.close();
  //(2)                                determining the solution by backtracking
  while( !BackTracking.empty() )
    {
      int n0=(BackTracking.top() ).index1;
      int n1=(BackTracking.top() ).index2;
      hhh[n0] += hhh[n1]*(BackTracking.top() ).value;
      BackTracking.pop();
    }
  for(int n=0; n<NNN; ++n)
    {
      if(abs(hhh[n])<1.0e-8) hhh[n]=0;
      else ++N1;
    }
  cout<<"Number of non-zero entries in reconstructed solution is "<<N1<<endl;
  //(3)                                       return the reconstructed solution
  ofstream output(fname.c_str() );
  output<<NNN<<"  "<<N1<<endl<<endl;
  for(int n=0; n<NNN; ++n) output<<hhh[n]<<endl;
  output.close();
  return;
}

//                  update the guidance vector and then identify its lead index
void CompSense::DualAscent(int& leadindex, double& distance)
{
  //(1)                                                  the initial gap vector
  gamma=0;
  for(int n=0; n<actNNN; ++n)
    {
      int position0=n*MMM;
      double value=0;          //value is the n-th entry of the guidance vector
      for(int m=0; m<MMM; ++m)
	value += bbb[m]*DDD[position0+m];
      for(int m=0; m<MMM; ++m)
	gamma[m] -= DDD[position0+m]*value;
    }
  gamma += zzz;
  //(2)                                                   dual ascent iteration
  int daiter=0;
  while(daiter<maxIter)
    {
      ++daiter;
      eta=0;
      for(int n=0; n<actNNN; ++n)
	{
	  int position0=n*MMM;
	  double value=0;              //value is the n-th entry of (D^T gamma)
	  for(int m=0; m<MMM; ++m)
	    value += gamma[m]*DDD[position0+m];
	  for(int m=0; m<MMM; ++m)
	    eta[m] += DDD[position0+m]*value;
	}
      double overlap_ab=0;
      double overlap_bb=0;
      for(int m=0; m<MMM; ++m)
	{
	  overlap_ab += gamma[m]*eta[m];
	  overlap_bb += pow(eta[m], 2);
	}
      double varepsilon=(overlap_bb>1.0e-15? (overlap_ab/overlap_bb) : 0);
      for(int m=0; m<MMM; ++m)
	{
	  bbb[m] += varepsilon*gamma[m];
          gamma[m] -= varepsilon*eta[m];
	}
    }
  distance=0;
  for(int m=0; m<MMM; ++m)
    distance += abs(gamma[m]);
  distance /= MMM;
  cout<<" "<<distance;
  double maximum = -1;
  leadindex= -1;
  for(int n=0; n<actNNN; ++n)
    {
      double value=0;
      int position0=n*MMM;
      for(int m=0; m<MMM; ++m)
	value += bbb[m]*DDD[position0+m];
      if(value<0) value= -value;
      if(value>maximum)
	{
	  leadindex=n;
	  maximum=value;
	}
    }
  return;
}
