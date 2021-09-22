#include<iostream>
using namespace std;
#include<string>

//重载递增运算符
//自定义整型
class MyInteger
{
    friend ostream& operator<<(ostream & cout, MyInteger myint);
public:
    MyInteger()
    {
        m_Num = 0;
    }
    //重载前置++运算符 返回引用为了一直对一个数据进行递增操作
    MyInteger & operator++()
    {
        //先进行++运算
        m_Num++;
        //再将自身做一个返回
        return *this;
    }

    //重载后置++运算符 int代表占位参数可以用于区分前置和后置递增
    MyInteger operator++(int)
    {
        //先 记录当时结果
        MyInteger temp = *this;
        //后递增
        m_Num++;
        //最后记录返回结果
        return temp;
    }
private:
   int m_Num;
};

//重载以下左移<<元算符
ostream& operator<<(ostream& cout, MyInteger myint)
{
    cout<<myint.m_Num;
    return cout;
}
void test01()
{
    MyInteger myint;
    cout<<myint<<endl;
    cout<<++(++myint)<<endl;
}

void test02()
{
  MyInteger myint;
  cout<<myint++<<endl;
  cout<<myint<<endl;
}
//递增运算符重载-- ++
int main()
{
  //test01();
  test02();
}