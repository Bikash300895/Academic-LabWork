#include <iostream>
using namespace std;
int ncr[10][10];

void NCR()
{
    ncr[0][0]=1;
    int i,j;
    int n=10;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=i;j++)
        {
            //if(j>i) ncr[i][j]=0;
            //else
            if(j==i||j==0) ncr[i][j]=1;
            else ncr[i][j]=ncr[i-1][j-1]+ncr[i-1][j];
        }
    }
}

int main()
{
    NCR();
    int i,j;
    cin>>i>>j;
    cout<<ncr[i][j];
}
