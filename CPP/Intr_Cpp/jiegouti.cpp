#include<iostream>
using namespace std;
#include<string>

struct Student
{
    string name;
    int age;
    int height;
};

int main()
{
    //struct Student s1;
    //s1.name = "张唢呐";
    //s1.age = 90;
    //s1.height = 173;
    
    //cout<<"姓名 "<<s1.name<<" 年龄 "<<s1.age<<" 身高 "<<s1.height<<end
    struct Student stuArray[3]=
    {
        {"张三", 18,  175},
        {"李四", 20,  198},
        {"王五", 23,  191}
    };
    //3.给结构体数组中的元素赋值
    stuArray[2].name="蓝猫";
    stuArray[2].age=22;
    stuArray[2].height=122;
    //4.遍历结构体数组
    for (int i = 0;i<3;i++)
    {
        cout<<"姓名 "<<stuArray[i].name
            <<" 年龄 "<<stuArray[i].age
            <<" 身高 "<<stuArray[i].height<<endl;
           
    }
}