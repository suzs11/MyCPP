#include<iostream>
using namespace std;
#include<string>

class Calculate
{
public: 
	int getResult(string oper)
	{
         if (oper =="+")
		{
         return num1 + num2;
		}
		else if (oper =="-")
		{
		return num1 - num2;
		}
		else if (oper=="*")
		{
		return num1 * num2;
		}
		//如果向扩展的新的功能， 需求该源码
		//在真的开发中提倡开闭原则
		//开闭原则： 对扩展进行开发对修改进行关闭
	}
	int num1;
	int num2;
};
void test()
{
		Calculate c;
		c.num1  = 100;
		c.num2 = 200;
		cout<<c.num1<<" + "<<c.num2<<" = " <<c.getResult("+") <<endl;
		cout<<c.num1<<" - "<<c.num2<<" = " <<c.getResult("-") <<endl;
		cout<<c.num1<<" * "<<c.num2<<" = " <<c.getResult("*") <<endl;
}
//利用多态实现计算器
//实现计算器抽象类
class AbstractCalculatr
{
public:
		virtual int getResult()
		{
		return 0;
		}
		int num1;
		int num2;
};

//加法计算类
class AddCalculator:public AbstractCalculatr
{
		public:
		int getResult()
		{
		return num1 + num2;
		}
};
class SubCalculator:public AbstractCalculatr
{
		public:
   int getResult()
	 {
	 return num1 - num2;
	 }
};

class MutCalculator:public AbstractCalculatr
{
		public:
   int getResult()
	 {
	 return num1 - num2;
	 }
};
										
class ChuCalculator:public AbstractCalculatr
{
		public:
   int getResult()
	 {
	 return num1 - num2;
	 }
};

void test01()
{
  //多态使用条件
	//父类的指针或者引用指向子类对象
	//加法运算
	AbstractCalculatr *abc = new  AddCalculator;
	abc->num1 = 10;
	abc->num2 = 10;
	cout <<abc->num1 <<"+"<<abc->num2<< "="<<abc->getResult()<<endl;
	abc = new  MutCalculator;
	abc->num1 = 10;
	abc->num2 = 10;
	cout <<abc->num1 <<"*"<<abc->num2<< "="<<abc->getResult()<<endl;
	abc = new  ChuCalculator;
	abc->num1 = 10;
	abc->num2 = 10;
	cout <<abc->num1 <<"-"<<abc->num2<< "="<<abc->getResult()<<endl;
}
int main()
{
  // test();
	test01();
}
