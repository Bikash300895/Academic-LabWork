#include <iostream>

using namespace std;

int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b, a%b);
}

int main()
{
    int a,b;
    cin>>a>>b;
    if(b>a)
    {
        int temp;
        temp=a;
        a=b;
        b=temp;
    }
    int c=gcd(a,b);
    cout<<c;
}
