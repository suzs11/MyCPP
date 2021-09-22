#include<iostream>
using namespace std;

int main()
//外层执行一次， 内层执行一周
//外层循环
//{for(int j=0; j<10;j++)
//  {
//    //内层的循环
//    for(int i=0;i<10;i++)
//    {
//        cout<<"* ";
//    }
//    cout<<endl;
//  }
//}
{
    for (int i=1;i<10;i++)
    {
        for (int j=1;j<=i;j++)
        {
            cout<< j<<"*"<<i<<"="<<i*j<<" ";
        }
        cout<<endl;
    }
}