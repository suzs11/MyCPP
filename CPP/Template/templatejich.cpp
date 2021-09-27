#include<iostream>
using namespace std;
#include<string>

//类模板的继承
template <class T>
class Base
{
  T m;
};

//class Son :public Base//错误必须要知道父类中的T的类型才能继承给子类
class Son:public Base<int>
{


};
void test01()
{
 Son s1;
}
//如果想灵活指定父类中T类型的， 子类也需要变类模板
template <class T1, class T2>
class Son2:public  Base<T2>
{
public:
	Son2()
	{
	 cout<<"T1的数据类型为"<<typeid(T1).name()<<endl;
	 cout<<"T2的数据类型为"<<typeid(T2).name()<<endl;
	 T1 obj;
	}
};
void test02()
{
   Son2<int, char>S2;
}
int main()
{
//test01();
test02();
}
