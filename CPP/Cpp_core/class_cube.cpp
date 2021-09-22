#include<iostream>
using namespace std;
#include<string>

class Cube
{
public:
    void setL(int l)
    {
        c_L = l;
    }
    void getL()
    {
        return c_L;
    }

    void setL(int w)
    {
        c_W = w;
    }
    void getL()
    {
        return c_W;
    }
    
    void setL(int h)
    {
        c_H = h;
    }
    void getL()
    {
        return c_H;
    }
    
    int calcluateS()
    {
        int S = 2*(c_L*c_W+ c_L*c_H+c_W*c_H);
        return S;
    }
    int calcluateV()
    {
        int V = c_L*c_W*c_H;
        return V;
    }


private:
    int c_L;
    int c_W;
    int c_H;

};
void issame()
{
    
}

int main()
{

}