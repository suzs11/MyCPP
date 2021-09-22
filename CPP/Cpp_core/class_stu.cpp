#include <iostream>
using namespace std;
#include <string>

class Student
{
public:
  string m_Name;
	int age;
	void xinxi()
	{
	  cout<<"姓名"<<m_Name<<endl;
		cout<<"年龄"<<age<<endl;
	}
	//给姓名赋值
	void setName(string name)
	{
		m_Name = name;
	}
    //给学号赋值
	void setAge(int age_)
	{
		age = age_;
	}
};

int main()
{
    Student s1;
		//s1.m_Name = "张三";
		//s1.age = 28;
		s1.setName("张三");
		s1.setAge(30);
		s1.xinxi();
}
