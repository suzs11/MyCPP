#include<iostream>
using namespace std;
 
 //关系运算符重载
 class Person
 {
public:
   Person(string name, int age)
   {
       m_Name = name;
       m_Age = age;
   }
   //重载==号
   bool operator==(Person &p)
   {
       if(this->m_Name==p.m_Name && this->m_Age==p.m_Age)
       {
           return true;
       }
       else
       {
           cout<<"p1和p2不相等"<<endl;
       }
    return false;
   }
   bool operator!=(Person &p)
   {
       if(this->m_Name==p.m_Name && this->m_Age==p.m_Age)
       {
           return false;
       }
       else
       {
         return true;
       }

   }
   string m_Name;
   int m_Age;
 };

 void test01()
 {
     Person p1("Tom", 25);
     Person p2("Jerry", 25);
     if (p1 == p2)
     {
         cout<<"p1和p2是相等的"<<endl;
     }
     else
     {
         cout<<"p1 和 p2是不相等！"<<endl;
     }
     if (p1 != p2)
     {
         cout<<"p1和p2是不相等的"<<endl;
     }
     else
     {
         cout<<"p1 和 p2是相等的！"<<endl;
     }
 }
 int main()
 {
    test01();
 }