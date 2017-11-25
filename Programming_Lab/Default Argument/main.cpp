#include <iostream>
using namespace std;

int sum(int x=0, int y=0, int z=0)
{
    return x+y+z;
}

int main()
{
    int s=sum(1,2,3);
    cout<<s<<endl;
    return 0;
}
