#include<iostream>
using namespace std;
 #include<string>

class CPU
{
		public:
				virtual void calculate() = 0;

};
class VideoCard
{
		public:
				virtual void display() = 0;

};
class Memory
{
		public:
				virtual void storage() = 0;

};

//电脑类
class Computer
{
public:
		Computer(CPU * cpu, VideoCard * vc, Memory * mem)
		{
		  m_cpu = cpu; 
			m_vc = vc;
		  m_mem = mem;	
		}
		//提供工作的函数
		void work()
		{
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
		}

private:
		CPU * m_cpu;
		VideoCard * m_vc;
    Memory * m_mem;
};

//具体厂商
//Intel厂商
class IntelCPU :public CPU
{
public:
		virtual void calculate()
		{
		cout<<"Intel的CPU开始急速计算"<<endl;
		}
};
class IntelVideoCard :public VideoCard
{
public:
		virtual void display()
		{
		cout<<"Intel的显卡开始显示了！"<<endl;
		}
};
class IntelMemory :public Memory
{
public:
		virtual void storage()
		{
		cout<<"Intel的内存条开始存储了"<<endl;
		}
};

//Lenovo厂商
class LenovoCPU :public CPU
{
public:
		virtual void calculate()
		{
		cout<<"Lenovo的CPU开始急速计算"<<endl;
		}
};
class LenovoVideoCard :public VideoCard
{
public:
		virtual void display()
		{
		cout<<"Lenovo的显卡开始显示了！"<<endl;
		}
};
class LneovoMemory :public Memory
{
public:
		virtual void storage()
		{
		cout<<"Lenovo的内存条开始存储了"<<endl;
		}
};

void test01()
{
//第一台电脑的零件
CPU * intelCpu = new IntelCPU;
VideoCard * intelCard = new IntelVideoCard;
Memory * intelMem = new IntelMemory;

//创建第一台电脑
Computer * computer1 = new Computer(intelCpu, intelCard, intelMem);
computer1->work();
delete computer1;

}

int main()
{
test01();
}
