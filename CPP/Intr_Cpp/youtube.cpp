#include <iostream>
#include <string> //用c++风格的字符串时候， 要包含这个头文件
	using namespace std;

int main()
{

	int num1 = 1;
	int num2 = 2;
	int sum3 = num1 + num2;
	cout<< "两个数的和是:" << sum3<< endl ;
	float f1 = 3.14f;
	cout <<"f1占用的内存空间" <<sizeof(f1) <<endl;
	double dd1 = 3.14;
	cout <<"dd1=" << dd1 <<endl;
	char str[] = "work hard";
	cout << str <<endl;
	// C++ 风格的写法
	//包含头文件 #include <string>
	string str2 = "you are a beautiful girl";
	cout << str2<< endl;

	bool flag = true;
	cout << flag <<endl;
	bool flag2 = false;
	cout << flag2 <<endl;
    cout << "bool类型所占空间的内存"<<sizeof(flag2)<<endl;
	int a1 = 10;
	a1++;
	cout <<"a="<< a1 <<endl;
	int a =20;
	int b = 21;
	cout <<(a==b) <<endl;
	int score = 0;
	cout<<"请输入一个分数"<<endl;
	cin >> score;
	cout <<"你输入的分数是"<< score << endl;
	if(score>600)
	{
      cout <<"我考上了一本大学"<<endl;
	  if (score>650){
		  cout<<"你考上了清华大学"<<endl;}
      else{ cout<<"你考上了北京大学"<<endl;};
	  
	}
	else if (score>500){
		cout<<"恭喜您考上二本大学"<<endl;
	}
	else { cout<<" 成绩考的有些差"<<endl;};
    float num_1 = 0;
	float num_2 = 0;
	float num_3 = 0;
	cout<<"请输入小猪A的重量"<<endl;
	cin>>num_1;
	cout<<"请输入小猪B的重量"<<endl;
	cin>>num_2;
	cout<<"请输入小猪C的质量"<<endl;
	cin>>num_3;
    cout<<"小猪A的质量是"<<num_1<<endl;
	cout<<"小猪B的质量是"<<num_2<<endl;
	cout<<"小猪C的质量是"<<num_3<<endl;
    if (num_1>num_2){
		if (num_1>num_3){cout<<"最重的小猪是A";}
		else if (num_1<num_3){cout<<"最重的小猪是C";}
		else {cout<<"小猪B和小猪C一样重";}
	}
	else if (num_1<num_2){
        if (num_2>num_3){cout<<"最重的小猪是B";}
		else if (num_2<num_3){cout<<"最重的小猪是C";}
		else {cout<<"小猪B和小猪C一样中";}
	}
	else {
		if (num_2=num_3){cout<<"三头猪一样重";}
		else if(num_2>num_3){cout<<"小猪A和小猪B一样重,且比小猪C重";}
		else {cout<<"小猪C最重";}
	}
	int a_1 = 1;
	int a_2 = 2;
	int a_3 = 0;
	a_3 = (a_1>a_2? a_1:a_2);
	cout<<a_3<<endl;
	return 0;

}