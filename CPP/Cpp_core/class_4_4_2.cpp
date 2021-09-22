#include<iostream>
using namespace std;
#include<string>

class Building;
class goodGay
{
public: 
    goodGay();
    void visit(); //参观函数 访问Building中的属性
private:
    Building * building;
};

class Building
{
    //GoodGay类是本类的好基友， 可以访问本类中私有成员
    friend class goodGay;
public:
    Building();
public:
   string m_SittingRoom; //客厅
private:
   string m_BedRoom;  //卧室
};

//类外写成员函数
Building::Building()
{
    m_SittingRoom = "客厅";
    m_BedRoom = "卧室";
}

goodGay::goodGay()
{
    //创建建筑物对象
    building =  new Building;
}

void goodGay::visit()
{
    cout<<"好基友正在访问： "<<building->m_SittingRoom<<endl;
    cout<<"好基友正在访问： "<<building->m_BedRoom<<endl;
}

void test01()
{
    goodGay gg;
    gg.visit();
}

int main()
{
   test01();
}