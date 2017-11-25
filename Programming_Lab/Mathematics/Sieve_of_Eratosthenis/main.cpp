#include <iostream>
#include<math.h>

using namespace std;

int main()
{
    int status[101]={0};
    int sq=sqrt(100);
    for(int i=4; i<=100; i+=2)
        {
            status[i]=1;
        }
    for(int i=3; i<=sq; i+=2)
    {
        if(status[i]==0)
        {
            for(int j=2*i;j<=100;j+=i) {status[j]=1;}
        }
    }
    status[1]=0;

    for(int i=1; i<100; i++)
    {
        if(status[i]==0)
        {
            cout<<i<<" ";
        }
    }
}
