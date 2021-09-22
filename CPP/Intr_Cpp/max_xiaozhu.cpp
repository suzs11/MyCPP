#include<iostream>
using namespace std;

int main()
{
    //1.创建5只小猪体重的数组
    int arr[5]= {300, 350, 200, 500, 250};
    //2.从数组中找到最大值
    int max = 0;
    for (int i=0; i<5; i++)
    {
        //cout<<rr[i]<<endl;
        //如果访问的数组中的元素比我认定的最大值还大，更新最大值
        if (arr[i]>max)
        {
            max = arr[i];
        }
    }
    //3.打印最大值
    cout<<"最重的小猪体重为："<< max <<endl;
}