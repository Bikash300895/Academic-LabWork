#include <iostream>

using namespace std;

int Bigmod(int a,int b,int M)
{
    if(b==0) return 1%M;
    int x=Bigmod(a,b/2,M);
    x=(x*x)%M;
    if(b%2==1) x=(x*a)%M;
    return x;
}

int main()
{
    int n=Bigmod(2,6,5);
    cout<<n;
}
