#include <iostream>
#include <algorithm>
using namespace std;

int co(int n, int k)
{
    /*if(k==0||k==n) return 1;
    else return co(n-1,k-1)+co(n-1,k);*/

    int c[n+1][k+1];
    int i,j;

    for(i=0; i<=n; i++)
    {
        for(j=0; j<=min(i,k); j++)
        {
            if(j==0||j==i) c[i][j]=1;
            else c[i][j]=c[i-1][j-1]+c[i-1][j];
        }
    }
    return c[n][k];
}

int main()
{
    cout<<co(5,2);
}
