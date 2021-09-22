#include<iostream>
#include<sstream>
using namespace std;

int main()
{
   //1.数据类型， 数组名[行数][列数]；
   int arr[2][3];
   arr[0][0] = 1;
   arr[0][1] = 2;
   arr[0][2] = 3;
   arr[1][0] = 4;
   arr[1][1] = 5;
   arr[1][2] = 6;
   // cout<<arr[0][0]<<endl;
   // cout<<arr[0][1]<<endl;
   // cout<<arr[0][2]<<endl;
   // cout<<arr[1][0]<<endl;
   // cout<<arr[1][1]<<endl;
   // cout<<arr[1][2]<<endl;
   //外层循环打印行数， 内层循环打印列数
   //for(int i=0;i<2;i++)
   //{
   //    for(int j=0;j<3;j++)
   //    {
   //        cout<<arr[i][j]<<endl;
   //    }
   //}
   //2.数据类型 数组名[行数][列数] = {{数据1，数据2}，{数据3，数据4}}；
   //int arr2[2][3] = 
   //{
   //    {1,2,3},
   //    {4,5,6}
   //};
   //for(int i=0;i<2;i++)
   //{
   //    for(int j=0;j<3;j++)
   //    {
   //        cout<<arr2[i][j]<<" ";
   //    }
   //    cout<<endl;
   //}
   //3.数据类型 数组名[行数][列数] = {数据1，数据2，数据3，数据4}；
   //int arr3[2][3] = {1,2,3,4,5,6};
   //for(int i=0;i<2;i++)
   // {
   //     for(int j=0;j<3;j++)
   //     {
   //         cout<<arr3[i][j]<<" ";
   //     }
   //     cout<<endl;
   // }
   //4.数据类型 数组名[][列数] = {数据1， 数据2， 数据3，数据4}
   int arr4[][3] = {1,2,3,4,5,6};
   for (int i=0;i<2;i++)
   {
       for(int j=0;j<3;j++)
       {
           cout<<arr4[i][j]<<" ";
       }
    cout<<endl;
   }
   cout<<"二维数组所占内存空间为："<<sizeof(arr4)<<endl;
   cout<<"二维数组第一行所占内存空间为："<<sizeof(arr4[0])<<endl;
   cout<<"二维数组第一个元素所占内存空间为："<<sizeof(arr4[0][0])<<endl;
   cout<<"二维数组行数为： "<<sizeof(arr4)/sizeof(arr4[0])<<endl;
   cout<<"二维数组列数为： "<<sizeof(arr4[0])/sizeof(arr4[0][0])<<endl;
   //2.可以查看二维数组的首地址
   cout<<"二维数组首地址为： "<< arr4<<endl;
   cout<<"二维数组第一行首地址："<<arr4[0]<<endl;
}