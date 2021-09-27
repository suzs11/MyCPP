#include<iostream>
using namespace std;
#include<string>


//类模板成员函数类外实现
template <class T1, class 2》
class Person
{
	public:
		Person(T1 name, T2 age)
		{
		this->m_Name = name;
	  this->m_Age =age;		
		}
		void showPerson()
		{
	  cout<<"姓名"<<this->m_Name<<"年龄： "<<this->m_Age<<endl;
		}
T2 m_Name;
T1 m_Age;

}



int main()
{


}
