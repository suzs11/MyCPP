#include<iostream>
using namespace std;

//动物
class Animal
{
    public:
      int m_Age;
};

//羊类
class Sheep: public Animal{};

//驼类
class Tuo: public Animal{};

//羊驼类
class Yangtuo: public Sheep, public Tuo{};

void test01()
{
    Yangtuo st;
    st.Sheep::m_Age = 18;
    st.Tuo::m_Age = 20;
    cout<<"yang m_Age = " <<st.Sheep::m_Age<<endl;
    cout<<" Tuo m_Age = " <<st.Tuo::m_Age<<endl;
}
int main()
{
  test01();
}