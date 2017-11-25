// Fibonacii Number
#include <iostream>

int Fibonacii(int n)
{
    if(n==0) return 0;
    if(n==1) return 1;
    return Fibonacii(n-1)+Fibonacii(n-2);
}

using namespace std;

int main()
{
    int n;
    cin>>n;
    cout<<Fibonacii(n);
}
