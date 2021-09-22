#include<iostream>
using namespace std;

#include<string>

struct Hero
{
  string name;
  int age;
  string gender;
};
//冒泡排序 实现年龄升序排序
void bubbleSort(struct Hero yingxiong[], int len)
{
     for (int i=0;i<len-1;i++)
     {
         for(int j=0;j<len-i-1;j++)
         {
             if(yingxiong[j].age>yingxiong[j+1].age)
             {
                 //如果j下标的元素年龄，大于j+1下标的元素的年龄， 交换两个元素
                 struct Hero temp = yingxiong[j];
                 yingxiong[j] = yingxiong[j+1];
                 yingxiong[j+1] = temp;
             }
         }    
     }
}
void printHero(struct Hero yingxiong[],  int len)
{
    for(int i=0;i<len;i++)
    {
        cout<<"姓名 "<<yingxiong[i].name
            <<" 年龄 "<<yingxiong[i].age
            <<" 性别 "<<yingxiong[i].gender<<endl;
    }
}
int main()
{
    struct Hero yingxiong[5] = 
    {
        {"刘备",23,"男"},
        {"关羽",22,"男"},
        {"张飞",20,"男"},
        {"赵云",21,"男"},
        {"貂蝉",19,"女"}
    };
    int len = sizeof(yingxiong) / sizeof(yingxiong[0]);
    // for (int i=0;i<len;i++)
    // {
    //    cout<<"姓名 "<<yingxiong[i].name
    //        <<" 年龄 "<<yingxiong[i].age
    //        <<"性别 " <<yingxiong[i].gender<<endl;
    // }
    //3.对数组进行排序， 按照年龄进行升序排列
    bubbleSort(yingxiong, len);
    //4.将排序后的结果打印输出
    printHero(yingxiong, len);
}