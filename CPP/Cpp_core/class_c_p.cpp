#include<iostream>
using namespace std;
#include<string>

class Point
{
public:
    int setX(int X)
    {
        m_X = X;
    } 
    int getX()
    {
        return m_X;
    }
    int setY(int Y)
    {
        m_X = Y;
    } 
    int getY()
    {
        return m_Y;
    }
private: 
  int m_X;
  int m_Y;
};

class Circle
{
  public:
   void setR(int r)
   {
         m_R = r;
   }
   int getR()
   {
       return m_R;
   }
   //设置圆心
   void setCenter(Point center)
   { 
      m_Center = center;
   }
   //获取圆心
   Point getCenter()
   {
       return m_Center;
   }
  private:  

  int m_R;  //半径
  Point m_Center;//圆心
};

//判断点和圆之间的关系
void isInCircle(Circle &c, Point &p)
{
    //计算两点之间的距离 平方

    //计算半径的平方
}
int main()
{

}