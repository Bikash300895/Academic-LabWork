#include <iostream>
#include <limits.h>
using namespace std;

int main()
{
    int n=4,a[4][4]={0,-2,-7,0,9,2,-6,2,-4,1,-4,1,-1,8,0,-2};
    //{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};//
    for(int i=1; i<n; i++)
    {
        a[i][0]+=a[i-1][0];
    }

    for(int j=1; j<n; j++)
    {
        a[0][j]+=a[0][j-1];
    }

    for(int i=1; i<n; i++)
    {
        for(int j=1; j<n; j++)
        {
            a[i][j]=a[i][j]+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        }
    }
    int max=INT_MIN;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            for(int k=1; k<n; k++)
            {
                for(int l=j; l<n; l++)
                {
                    int temp=a[k][l];
                    if(i>0) temp-=a[i-1][l];
                    if(j>0) temp-=a[k][j-1];
                    if(i>0 && j>0) temp+=a[i-1][j-1];

                    if(temp>max) max=temp;
                }
            }
        }
    }
    cout<<max;
    /*for(int i=0; i<n; i++)
    {
        for(int j=0; j<n ;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }*/
}

