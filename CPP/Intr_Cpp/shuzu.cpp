#include<iostream>
using namespace std;

int main()
{
    //2.数据类型 数组名[数组长度] ={值1， 值2，值3，...}
    //如果在初始化数据没有全部填写完会用0来填补剩余的数据
    int arr2[5] = {10,20,30,40,50};
    //cout<<arr2[0]<<endl;
    //cout<<arr2[1]<<endl;
    //cout<<arr2[2]<<endl;
    //cout<<arr2[3]<<endl;
    //cout<<arr2[4]<<endl;
    //利用循环， 输出数组中的元素
    //for(int i=0;i<5;i++)
    //{
    //    cout<<arr2[i]<<endl;
    //}
    //3.数据类型， 数组名[]={值1， 值2，....}
    //定义数组的时候， 必须有初始长度
    int arr3[] = {20,30,40,4,90, 60,80,70};
    for (int i=0;i<8;i++)
    {
      cout<<arr3[i]<<endl;
    }


}