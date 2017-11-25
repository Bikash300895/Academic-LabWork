#include <iostream>
#include <algorithm>
using namespace std;

/*int coin_exchange(int s[], int m, int n)
{
    if(n==0) return 1;
    if(n<0) return 0;
    if(m<0) return 0;
    return coin_exchange(s,m-1,n)+coin_exchange(s,m,n-s[m-1]);
}*/
int coin_exchange(int s[], int m, int n)
{
    int i,j,x,y;
    int table[n+1][m];
    for(i=0; i<m; i++) table[0][i]=1;

    for(i=1; i<n+1; i++)
    {
        for(j=0; j<m ;j++)
        {
            x=(i-s[j]>=0)? table[i-s[j]][j]:0;
            y=(j>=1 )? table[i][j-1]:0;
            table[i][j]=x+y;
        }
    }
    return table[n][m-1];
}

int main()
{
    int s[]={1,2,3};
    cout<<coin_exchange(s,3,4);
    return 0;
}
