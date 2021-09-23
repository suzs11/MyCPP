#include<iostream>
using namespace std;
#include<string>

template<class T>
void mySwap(T &a, T &b)
{
   T temp = a;
	 a = b;
	 b = temp;
}

template<class T>
void mySort(T arr[], int len)
{
 for(int i=0; i<len; i++)
 {
   int max = i;
	 for(int j=i+1; j<len;j++)
	 {
	  if(arr[max]< arr[j])
		{
		 max=j; //更新最大值下标
		}
	 }
	 if(max != i)
	 {
	   //交换max和i元素
     mySwap(arr[max], arr[i]);
	 }
 }
}

//提供打印数组模板
template<class T>
void printArray(T arr[], int len)
{
  for(int i=0; i<len; i++)
  {
	 cout<<arr[i]<<" ";
	}
	cout <<endl;
}

void test01()
{
// 测试char数组
  char charArr[] = "badcfe";
	int num = sizeof(charArr) / sizeof(char);
	mySort(charArr, num);
	printArray(charArr, num);
}

void test02()
{
   //测试int数组
	 int intArr[] = {7,3,6,7,2,4,1,5};
	 int num = sizeof(intArr) / sizeof(int);
	 mySort(intArr, num);
	 printArray(intArr, num);

}
int main()
{
 //test01();
 test02();
}
