#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

void printLPS(char *str, int x, int y)
{
    for(int i=x; i<=y; i++)
    {
        cout<<str[i];
    }
    cout<<endl;
}

int LPS(char *str)
{
    int n=strlen(str);
    bool table[n][n];
    memset(table,0,sizeof(table));

    int maxlen=1;
    for(int i=0; i<n; i++)
        table[i][i]=true;

    int start=0;
    for(int i=0; i<n-1; i++)
    {
        if(str[i]==str[i+1])
        {
            table[i][i+1]=true;
            start =i;
            maxlen=2;
        }
    }

    for(int k=3; k<=n; k++)
    {
        for(int i=0; i<n-k+1; i++)
        {
            int j= i+k-1;
            if(table[i+1][j-1] && str[i]==str[j])
            {
                table[i][j]=true;
                if(k>maxlen)
                {
                    maxlen=k;
                    start=i;
                }
            }
        }
    }
    printLPS(str, start, maxlen+start-1);
    return maxlen;
}

int main()
{
    char str[]="banana";
    cout<<LPS(str)<<endl;
    return 0;
}
