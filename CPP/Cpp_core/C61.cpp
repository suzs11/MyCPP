#include<iostream>
using namespace std;
#include <fstream>
#include <string>

//函数调用运算符重载

//打印输出类
class MyPrint
{
public: 
  //和从在函数调用元算符
  void operator()(string test)
  {
      cout<<test<<endl;
  }
};
void test()
{
    MyPrint myPrint;
    myPrint("hello world");
    //使用起来非常像函数的调用， 因此称之为仿函数
}
//仿函数非常灵活， 没有固定的写法
//加法类
class MyAdd
{
public: int operator()(int num1, int num2)
         {
             return num1+num2;
         }
};
void test02()
{
    MyAdd myadd;
    int ret =myadd(100, 100);
    cout<<"ret = "<<ret<<endl;
}
int main()
{
  //test();
  test02();
}