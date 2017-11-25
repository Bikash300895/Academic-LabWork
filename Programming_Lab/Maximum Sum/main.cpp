#include <iostream>
#include <limits.h>
using namespace std;

int main()
{
    int n=3,a[3][3]={-1,1,2,0,3,4,0,-1,0};
    int i,j,k,l;

    for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(i>0) a[i][j]+=a[i-1][j];
                if(j>0) a[i][j]+=a[i][j-1];
                if(i>0&&j>0) a[i][j]-=a[i-1][j-1];
            }
        }

    int ans=INT_MIN;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            for(k=i; k<n; k++)
            {
                for(l=j; l<n; l++)
                {
                    int temp=a[k][l];
                    if(i>0) temp-=a[i-1][l];
                    if(j>0) temp-=a[k][j-1];
                    if(i>0 && j>0) temp+=a[i-1][j-1];
                    if(temp>ans) ans=temp;
                }
            }
        }
    }
    cout<<ans;
    return 0;

}
