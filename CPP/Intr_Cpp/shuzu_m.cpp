#include<iostream>
using namespace std;

int main()
{
    //1.可以统计整个数组自内存中的长度
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    cout<<"整个数组的占用的内存空间为"<< sizeof(arr)<<endl;
    cout<<"第一个数组元素占用内存空间为"<<sizeof(arr[0]) <<endl;
    cout<<"第二个数组元素的占用的内存空间为"<<sizeof(arr[1])<<endl;
    cout<<"个数"<<sizeof(arr)/sizeof(arr[0])<<endl;
    //2.可以获取数组自内存中的首地址
     cout<<"数组首地址为 "<< arr <<endl;
     cout<<"数组中第一个元素地址为： "<<&arr[0] <<endl;
     cout<<"数组中第二个元素地址为： "<<&arr[1] <<endl;
    //数组名是常量， 不可以进行赋值操作
    //arr = 100;
}