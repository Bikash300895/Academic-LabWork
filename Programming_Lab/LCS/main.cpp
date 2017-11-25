#include <iostream>
#include <cstring>
#include <algorithm>
#include <deque>
using namespace std;

int lcs(char *x, char *y, int m, int n)
{
    int lcs[m+1][n+1];
    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i==0||j==0)
                lcs[i][j]=0;
            else if(x[i-1]==y[j-1])
            {
                lcs[i][j]=lcs[i-1][j-1]+1;
                //cout<<x[i-1]<<" ";
            }

            else
            {
                int z=max(lcs[i-1][j],lcs[i][j-1]);
                lcs[i][j]=z;
            }

        }
    }

    int temp=lcs[m][n];
    deque<char> index;

    for(int i=m; i>0 ;i--)
    {
        for(int j=n; j>0; j--)
        {
            if(x[i-1]==y[j-1] && lcs[i][j]==temp)
            {
                index.push_front(x[i-1]);
                temp--;
            }
        }
    }
    for(char i:index)
        cout<<i<<" ";

    cout<<endl;
    return lcs[m][n];
}


int main()
{
  char X[] = "GXTXAYB";
  char Y[] = "AGGTAB";

  int m = strlen(X);
  int n = strlen(Y);

  printf("Length of LCS is %d\n", lcs( X, Y, m, n ) );

  return 0;
}
