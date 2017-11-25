#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float a=15.22227;
    cout<<setiosflags(ios::fixed);
    cout<<setprecision(6);
    cout<<setw(10);
    cout<<setfill('x');
    cout<<a;
    return 0;
}
