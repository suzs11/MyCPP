#include <iostream>
using namespace std;

int main()
{
    char*gnuplotPath = "/usr/bin/gnuplot";
    FILE* gp = _popen(gnuplotPath,"w");
    if (gp == NULL)
    {
        cout<<("Cannotopen gnuplot!\n")<<endl;;
        return 0;
        //exit(0);
    }
    fprintf(gp,"plot sin(x)\n");
    fprintf(gp,"pause mouse\n");//用户点击后退出
    _pclose(gp);
}