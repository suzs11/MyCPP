#include<iostream>
using namespace std;

//Java 
class BasePage
{
    public:
    void header()
    {
        cout<<"首页， 公开课 登陆 注册"<<endl;

    }
    void footer()
    {
        cout<<"帮助中心, 交流合作 站内地图"<<endl;
    }
    void left()
    {
        cout<<"Java, Pythono , C++"<<endl;
    }
};

//继承实现页面
//继承的好处， 减少重复的代码
//语法 class 子类 ： 继承方式 父类
//子类 称为 派生类
//父类 称为 基类
class Java: public BasePage
{
    public: 
    void content()
    {
        cout<<"java学科视频"<<endl;
    }
};
class Python: public BasePage
{
   public:
   void content()
   {
       cout<<"Python学科视频"<<endl;
   }
};
class CPP: public BasePage
{
   public:
   void content()
   {
       cout<<"CPP学科视频"<<endl;
   }
};
void test()
{   
    cout<<"java下载视频页面的如下： "<<endl;
    Java ja;
    ja.header();
    ja.footer();
    ja.left();
    ja.content();
    cout<<"----------------"<<endl;
    cout<<"Python下载视频页面的如下： "<<endl;
    Python py;
    py.header();
    py.footer();
    py.left();
    py.content();
    cout<<"----------------"<<endl;
    cout<<"CPP下载视频页面的如下： "<<endl;
    CPP cpp;
    cpp.header();
    cpp.footer();
    cpp.left();
    cpp.content();
    cout<<"----------------"<<endl;
}

int main()
{
   test();
}