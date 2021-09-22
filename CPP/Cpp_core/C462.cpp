#include<iostream>
using namespace std;

class Father
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

class Gson:public Father
{
public:
   void func()
   {
       int m_A = 20;
       int m_B = 30;
       int m_C = 50;
   }
};

int main()
{

}