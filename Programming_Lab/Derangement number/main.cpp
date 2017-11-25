#include <iostream>

using namespace std;

int D(int n)
{
    if(n==0) return 0;
    return (n-1)*D(n-1)+(n-1)*D(n-2);
}

int main()
{
    cout<<D(3);
}
