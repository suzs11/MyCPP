#include<iostream>
using namespace std;

int main()
{
  //1.先打印所有三位数字
  int num=100;
  do
  {
      //2.从所有三位数字中嗯找到水仙花数
      int  a = 0; //个位
      int b = 0; //十位
      int c = 0; //百位
       a = num%10;
       b = num/10 %10;
       c = num/100; 
      if (a*a*a +b*b*b+c*c*c == num)//如果是水仙花数才打印
      {
        cout<<num<<endl;
      }
      num++;
  }while(num<1000);
}