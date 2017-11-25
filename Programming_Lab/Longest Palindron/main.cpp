#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int lps(char *a, int k, int n)
{
    if(k==n) return 1;
    if(a[k]==a[n] && k+1==n) return 2;
    if(a[k]==a[n]) return lps(a,k+1,n-1) + 2;
    return max(lps(a,k,n-1),lps(a,k+1,n));
}
int main()
{
    char a[]="banana";
    int n=strlen(a);
    cout<<lps(a,0,n-1);
}
