#include<iostream>
using namespace std;


void mySwap(int &a, int &b)
{
   int temp = a;
	   a = b;
		 b = temp;

}
template<typename T>
void tSwap(T &a,  T &b)
{
   T temp = a;
	   a = b;
		 b = temp;
}

void test01()
{
   int a = 10;
	 int b = 20;
	 tSwap<int>(a, b);
	 //mySwap(a, b);
	 cout<<"a ="<<a<<endl;
	 cout<<"b ="<<b<<endl;
}

int main()
{
test01();
}
