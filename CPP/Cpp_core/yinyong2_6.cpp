#include<iostream>
using namespace std;

void showValue(const int& v)
{
    //v =1000;
    cout<<v<<endl;
}
int main()
{
   const int& ref=10;

   cout<<ref<<endl;
   int a = 10;
   showValue(a);
}