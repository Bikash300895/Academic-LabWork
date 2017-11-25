#include <iostream>
using namespace std;

int countString(int n)
{
    int a[n], b[n];
    a[0]=b[0]=1;
    for(int i=1; i<=n; i++)
    {
        a[i]=a[i-1]+b[i-1];
        b[i]=a[i-1];
    }
    return a[n];
}

int main()
{
    cout<<countString(3);
    return 0;
}
