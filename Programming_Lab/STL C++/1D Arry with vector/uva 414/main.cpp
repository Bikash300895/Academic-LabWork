#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n))
    {
        if (!n) break;
        int nofx[20]={0},max=0;
        char line[30];
        gets(line);
        for(int i=0; i<n; i++)
        {
            gets(line);
            for(int j=0; line[j]; j++)
            {
                if(line[j]=='X') nofx[i]++;
            }
            if(nofx[i]>max) max=nofx[i];
        }
        int ans=0;
        for(int i=0; i<n; i++)
        {
            ans+=(max-nofx[i]);
        }
        cout<<ans;
    }
    return 0;
}
