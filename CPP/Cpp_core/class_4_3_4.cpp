#include<iostream>
using namespace std;

//常函数
class Person
{
public:
    //this指针的本质 是指针常量  指针的指向是不可以修改的
    //Person * const this
    //在成员函数后面加const  修饰的是this指针 让指针指向的值也不可以修改
    void showPerson() const
    {
       //this->m_A = 100;
       //this = NULL;
    }
    void func()
    {

    }
    int m_A;
    mutable int m_B;//特殊遍历个， 即使在常函数中， 也可以修改指针的指向的, 加上关键字mutable
};

void test01()
{
    Person p;
    p.showPerson();
}
//常对象
void test02()
{
    Person p;//在对象前加上const, 变为常对象
    //p.m_A = 100;
    p.m_B = 100;
    //常对象只能调用常函数
    p.showPerson();
    //p.func(); //常对象不可以调用普通的成员函数 因为普通成员函数可以修改属性
}
int main()
{

}