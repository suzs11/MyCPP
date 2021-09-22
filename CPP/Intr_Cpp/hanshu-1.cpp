#include<iostream>
using namespace std;

//函数的定义
//语法；
//返回值类型 函数名 参数列表 函数体语句 return表达式

//加法函数，实现两个整型相加， 并将相加的结果进行返回
int add(int num1, int num2)
{
   int sum = num1+num2;
   return sum;
}
int main()
{
    int a=10;
    int b=20;
    //调用函数语法： 函数名称(参数)
    int sum = add(a, b);//调用是的a，b称为实际参数， 简称实参
    cout<<"sum = "<<sum<<endl;

    a = 100;
    b = 500;
    int c = add(a, b);
    cout<<"c = "<<c<<endl;

}