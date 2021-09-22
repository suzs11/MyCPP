#include<iostream>
using namespace std;

int& test01()
{
    static int a = 10;//局部变量存放在四区中的栈区
    return a;
}
int main()
{ 
    int &ref = test01();
    cout<<"ref = "<<ref<<endl;//第一次结果正确，是因为编译器做了保留
    cout<<"ref = "<<ref<<endl;//第二次结果错误是因为内存已经释放
    test01() = 1000;
    cout<<"ref = "<<ref<<endl;
    cout<<"ref = "<<ref<<endl;
}