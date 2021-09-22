#include <iostream>
using namespace std;

#include<string>

class AbstractDrinking
{
		public:
				virtual void Boil() = 0;
				virtual void Brew() = 0;
				virtual void PourInCup() = 0;
				virtual void PutSomething()  = 0;
				void makeDrink()
				{
				Boil();
				Brew();
				PourInCup();
				PutSomething();
				}

};

class Coffee: public AbstractDrinking
{
public:
				virtual void Boil()
				{
				 cout<<"主农夫山泉"<<endl;
				}	
				virtual void Brew()
				{
				cout<<"冲泡咖啡"<<endl;
				}
				virtual void PourInCup()
				{
				cout<<"倒入杯中"<<endl;
				}
				virtual void PutSomething()
				{
				cout<<"加入糖和牛奶"<<endl;
				}
};

class Tea: public AbstractDrinking
{
public:
				virtual void Boil()
				{
				 cout<<"加热开水"<<endl;
				}	
				virtual void Brew()
				{
				cout<<"冲泡茶叶"<<endl;
				}
				virtual void PourInCup()
				{
				cout<<"倒入杯中"<<endl;
				}
				virtual void PutSomething()
				{
				cout<<"加入枸杞"<<endl;
				}
};
void doWork(AbstractDrinking * abs)
{
   abs-> makeDrink();
	 delete abs;

}

void test()
{
 doWork(new Coffee);
 cout<<"--------------------------"<<endl;
 doWork(new Tea);

}
int main()
{
  test();
}
