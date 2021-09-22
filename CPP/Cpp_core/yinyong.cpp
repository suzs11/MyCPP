#include<iostream>
using namespace std;

//int main()
//{
//    //引用基本语法
//    //数据类型 &别名 = 原名
//    int a = 10;
//    int &b = a;
//    cout<<"a = "<<a<<endl;
//    cout<<"b = "<<b<<endl;
//    b = 100;
//    cout<<"a = "<<a<<endl;
//    cout<<"b = "<<b<<endl;
//}
int main()
{
    int a = 10;
    int b = 30;
    int &c = a;
    c = b;
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    cout<<"c = "<<c<<endl;
}