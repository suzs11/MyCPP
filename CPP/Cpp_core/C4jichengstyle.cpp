#include<iostream>
using namespace std;
#include <string>

class Base
{
public: 
int m_A;
protected:
int m_B;
private:
int m_C;
};
class son1:public Base
{
public:
int m_D;
};

void test()
{
    cout<<" size of the son = "<<sizeof(son1)<<endl;
}
int main()
{
test();
}