#include<iostream>
using namespace std;


//继承实现页面
//公共页面类
class BasePage
{
public:
  void header()
  {
      cout<<"首页， 公开课， 登陆， 注册(公共头部)"<<endl;
  }
  void footer()
  {
      cout<<"帮助中心， 交流合作， 站内网站 （公共底部）"<<endl;
  }
  void left()
  {
      cout<<"Java , python, C++ (公共课列表)"<<endl;
  }
};

//继承的好处：减少重复的代码
//语法： class 字类: 继承方式 父类
//子类 也称为派生类
//父类 也称为基类
//Java
class Java:public BasePage
{
public:
   void content()
   {
       cout<<"Java 公开视频页面"<<endl;
   }
};
//Python
class Python:public BasePage
{
public:
   void content()
   {
       cout<<"Python 公开视频页面"<<endl;
   }
};

//CPP
class CPP:public BasePage
{
public:
   void content()
   {
       cout<<"CPP 公开视频页面"<<endl;
   }
};
void test01()
{
    cout<<"Java下载视频页面如下："<<endl;
    Java ja;
    ja.header();
    ja.footer();
    ja.left();
    ja.content();

    cout<<"Python下载视频页面如下："<<endl;
    Python py;
    py.header();
    py.footer();
    py.left();
    py.content();

    cout<<"CPP下载视频页面如下："<<endl;
    CPP cpp;
    cpp.header();
    cpp.footer();
    cpp.left();
    cpp.content();
}
int main()
{
   test01();
}