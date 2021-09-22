#include <iostream>
#include <string>
using namespace  std;
int main()
//三目运算符
//创建三个变量 a ,b , c
//将a和b做比较，将变量大的赋值给变量c
//{
//int a=10;
//int b=20;
//int c=0;
//c = (a > b ? a : b);
//cout <<" c = " << c << endl;
////在C++中三目运算符返回的是变量， 可以继续赋值
//(a < b ? a : b) = 100;
//cout<<"a = "<<a <<endl;
//cout<<"b = "<<b <<endl;
//}
{
//switch语句
//给电影打分
//10~9经典
//8~7 非常好
//6~5一般
//5以下 烂片
//1、提示用户给电影打分
cout<<"请给电影进行打分"<<endl;
//2、用户开始打分
int score = 0;
cin>>score;
cout<<"您打的分数为:"<<score<<endl;

//3、根据用户输入的分数来提示用户最户的结果
switch(score)
{
    case 10:
    cout<<"您认为是经典电影"<<endl;
    break; //退出当前分支
    case 9:
    cout<<"您认为是经典电影"<<endl;break;
    case 8:
    cout<<"你认为电影非常好"<<endl;break;
    case 7:
    cout<<"您认为电影非常好"<<endl;break;
    case 6:
    cout<<"您认为电影一般"<<endl;break;
    case 5:
    cout<<"您认为电影一般"<<endl;break;
    default:
    cout<<"您认为这是烂片"<<endl;
}
}