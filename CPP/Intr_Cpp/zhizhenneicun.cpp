#include<iostream>
using namespace std;

int main()
{
    int a = 10;
    int *p = &a;
    cout<<"sizeof(int *) = "<<sizeof(int *)<<endl;
    cout<<"sizeof(int *) = "<<sizeof(double *)<<endl;
    cout<<"sizeof(int *) = "<<sizeof(float *)<<endl;
    cout<<"sizeof(int *) = "<<sizeof(char *)<<endl;
}