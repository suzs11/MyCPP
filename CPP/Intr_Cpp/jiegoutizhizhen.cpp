#include<iostream>
using namespace std;

#include<string>
struct student
{
    string names;
    int age;
    int score;
};

int main()
{
    //1. 创建学生结构体变量
    student s = {"张唢呐", 18,100};
    //2.通过指针指向结构体变量
    student * p = &s;
    //3.通过指针访问结构体变量中的数据
    cout<<"xianming "<<p->names
        <<" nianling "<<p->age
        <<" fenshu "<<p->score<<endl;
}
