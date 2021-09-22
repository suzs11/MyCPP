#include <iostream>
using namespace std;

const double PI = 3.14;

class Cirlce
{
public:
	int m_r;
	double calculateZC()
{
  return 2 * PI * m_r;
}
};

int main()
{
   Cirlce  cl;
	 cl.m_r  = 20;
	 cout<<"圆的周长为 "<<cl.calculateZC()<<endl;
	 return 0;
}
