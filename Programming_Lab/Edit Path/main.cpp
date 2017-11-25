#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int min(int x, int y, int z)
{
    return min(min(x, y), z);
}


int editDistDP(string str1, string str2, int m, int n)
{
    int arr[m+1][n+1];
    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i==0)
            {
                arr[i][j]=j;
            }
            else if(j==0)
            {
                arr[i][j]=i;
            }
            else if(str1[i-1]==str2[j-1])
            {
                arr[i][j]=arr[i-1][j-1];
            }
            else
            {
                arr[i][j]=1+min(arr[i-1][j-1],arr[i][j-1],arr[i-1][j]);
            }

        }
    }
    return arr[m][n];
}

int main()
{
    string str1 = "sunday";
    string str2 = "saturday";

    cout << editDistDP(str1, str2, str1.length(), str2.length());

    return 0;
}
