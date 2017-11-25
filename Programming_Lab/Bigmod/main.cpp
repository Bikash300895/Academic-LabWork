#include <iostream>
using namespace std;
int m=5;

int func(int n, int p)
{
    if(p==0) return 1;
    if(p%2==0)
    {
        int a=func(n,p/2);
        return ((a%m)*(a%m))%m;
    }
    else return ((n%m)*(func(n,p-1)%m))%m;
}

int main()
{
    int n=func(2,5);
    cout<<n;
}
