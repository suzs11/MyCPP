#include<iostream>
using namespace std;

//交换函数
//1、值传递
void swap01(int a,int b)
{
    int temp = a;
    a = b;
    b = temp;
}
//2、地址传递
void swap_z(int *a, int *b)
{
     int temp = *a;
    *a = *b;
    *b = temp;
}
//3、引用传递
void swap_y(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
int main()
{
    int a =10;
    int b =20;
    swap01(a, b);//值传递， 形参不会修饰实参
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    //swap_z(&a, &b);
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    swap_y(a, b);//引用传递，形参会修饰实参
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;

}