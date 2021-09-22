#include<iostream>
using namespace std;
#include "swap.h"

//函数的分文件编写
//实现恋歌数字进行交换的函数

////函数的声明
//void swap(int a, int b);
////函数的定义
//void swap(int a, int b)
//{
//    int temp = a;
//     a = b;
//     b = temp;
//     cout<<"a = "<<a<<endl;
//     cout<<"b = "<<b<<endl; 
//}

int main()
{
    int a = 10;
    int b = 20;
    swap(a, b);
}