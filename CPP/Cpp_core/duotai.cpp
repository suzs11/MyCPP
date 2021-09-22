#include<iostream>
using namespace std;


class Animal
{
public:
   virtual void speak()
   {
       cout<<"动物在说话"<<endl;
   }
};

class Cat: public Animal
{
public:
    void speak()
    {
        cout<<"猫在念经"<<endl;
    }
};

class Dog: public Animal
{
public:
    void speak()
    {
        cout<<"狗在汪汪汪"<<endl;
    }
};

void doSpeak(Animal &animal)
{
    animal.speak();
}

void test01()
{
    Cat cat;
    doSpeak(cat);

    Dog dog;
    doSpeak(dog);
}

int main()
{
  test01();
}