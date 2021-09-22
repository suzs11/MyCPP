#include<iostream>
using namespace std;
#include<string>

#define MAX 1000
//设计联系人的结构体
struct Person
{
    string m_Name;
    int m_Gender;
    int m_Age;
    string m_Phone;
    string m_Addr;

};
//设计通讯录的结构体
struct Addressbooks
{
    struct Person personArray[MAX];
    int m_Size;
};

//1.添加联系人
void addPerson(Addressbooks * abs)
{
    if(abs->m_Size == MAX)
    {
        cout<<"通讯录已满,无法添加"<<endl;
        return;
    }
    else
    {
        //添加联系人
        //姓名
        string name;
        cout<<"请输入姓名： "<<endl;
        cin>>name;
        abs->personArray[abs->m_Size].m_Name = name;
        //性别
        cout<<"请输入性别 "<<endl;
        cout<<"1---男"<<endl;
        cout<<"2---女"<<endl;
        int gender = 0;
        while (true)
        {
            cin>>gender;
            if(gender==1||gender==2)
            {
                abs->personArray[abs->m_Size].m_Gender = gender;
                break;
            }
            cout<<"输入有误，请重新输入 "<<endl;
        }
        //年龄
        cout<<"请输入年龄 "<<endl;
        int age = 0;
        cin>>age;
        abs->personArray[abs->m_Size].m_Age = age;
        //电话
        cout<<"请输入联系电话 "<<endl;
        string phone;
        cin>>phone;
        abs->personArray[abs->m_Size].m_Phone = phone;
        //住址
        cout<<"请输入家庭住址: "<<endl;
        string address;
        cin>>address;
        abs->personArray[abs->m_Size].m_Addr = address;
        //更新通讯录人数
        abs->m_Size++;
        cout<<"添加成功"<<endl;
        //system("pause");
        //system("cls");//清屏操作
    }
}
//显示联系人
void showPerson(Addressbooks * abs)
{
    if (abs->m_Size==0)
    {
        cout<<"通讯录记录为空"<<endl;
    }
    else
    {
        for(int i=0;i<abs->m_Size;i++)
        {
            cout<<"姓名"<<abs->personArray[i].m_Name<<"\t";
            cout<<" 性别 "<<(abs->personArray[i].m_Gender==1?"男":"女")<<"\t";
            cout<<" 年龄 "<<abs->personArray[i].m_Age<<"\t";
            cout<<" 电话 "<<abs->personArray[i].m_Phone<<"\t";
            cout<<" 家庭住址 "<<abs->personArray[i].m_Addr<<endl;
        }       
    }
}
//检测联系人是否存在， 如果存在，返回联系人所在数组中的具体位置，
// 不存在返回-1 参数 通讯录， 参数2 姓名
int isExit(Addressbooks * abs, string name)
{
     for(int i=0; i<abs->m_Size;i++)
     {
         //找到用户输入的姓名
         if (abs->personArray[i].m_Name==name)
         {
            return i;//找到了，返回这个人在数组中的下标编号
         }
     }
     return -1;//如果遍历结束都没有那么返回-1
}
//3.删除指定联系人
void deletePerson(Addressbooks * abs)
{
    cout<<"请输入您要删除的联系人"<<endl;
    string name;
    cin>>name;
    //ret==-1未查到， ret!=-1查到了
    int ret = isExit(abs, name);
    if(ret!=-1)
    {
       //查找到人， 要进行删除操作
       //删除李四，将李四户的数据向前移动， 
       //并且让通讯录中记录的人员个数做-1的操作
       for(int i=ret;i<abs->m_Size;i++)
       {
            //数据前移
            abs->personArray[i] = abs->personArray[i+1];
       }
       abs->m_Size;//更新通讯录中人员数
       cout<<"删除成功"<<endl;
       
    }
    else
    {
       cout<<"查无此人"<<endl;
    }

}
void showmenu()
{
    cout<<"**************************"<<endl;
    cout<<"******1、添加联系人*******"<<endl; 
    cout<<"******2、显示联系人*******"<<endl; 
    cout<<"******3、删除联系人*******"<<endl; 
    cout<<"******4、查找联系人*******"<<endl; 
    cout<<"******5、修改联系人*******"<<endl; 
    cout<<"******6、清空联系人*******"<<endl; 
    cout<<"******0、退出通讯录*******"<<endl; 
    cout<<"**************************"<<endl;
}
int main()
{
    //创建通讯录结构体变量
     Addressbooks abs;
    //初始化通讯录中当前人员的个数
    abs.m_Size = 0;
    int select = 0;
    while(true)
    {   
        showmenu();
        cin>>select;
        switch (select)
        {
        case 1://添加联系人
            addPerson(&abs);//利用地址传递， 可以修饰实参
             break;
        case 2://显示联系人
            showPerson(&abs);
            break;
        case 3://删除联系人
        //{
        //    cout<<"请输入删除联系人姓名： "<<endl;
        //    string name;
        //    cin >> name;
        //    if (isExit(&abs, name)==-1)
        //    {
        //        cout<<"查无此人"<<endl;
        //    }
        //    else
        //    {
        //        cout<<"找到此人"<<endl;
        //    }
        //}
            deletePerson(&abs);
            break;
        case 4://查找联系人
            break;
        case 5://修改联系人
            break;
        case 6://清空联系人
            break;
        case 0://退出通讯录
            cout<<"欢迎下次使用"<<endl;
            return 0;
            break;
        
        default:
            break;
        }
    }
    return 0;
}