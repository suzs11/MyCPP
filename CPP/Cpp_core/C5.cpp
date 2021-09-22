#include<iostream>
using namespace std;
#include <fstream> //头文件包含

//文本文件 ，写头文件fstream

void test01()
{
    //1、包含头文件

    //2、创建流对象
    ofstream ofs;
    //3、指定打开方式
    ofs.open("tets.txt", ios::out);
    //4、写内容
    ofs<<"姓名张三"<<endl;
    ofs<<"性别 男"<<endl;
    ofs<<"年龄 23"<<endl;
    ofs<<"身高 186"<<endl;
    ofs.close();
}
int main()
{
   test01();
}