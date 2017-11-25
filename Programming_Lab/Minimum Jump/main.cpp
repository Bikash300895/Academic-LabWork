#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int minimumJump(int arr[], int l, int r)
{

    if(l==r) return 0;
    if(arr[l]==0) return INT_MAX;
    int mini=INT_MAX;
    for(int i=l+1; i<=r && i<=l+arr[l]; i++)
    {
        int jumps=minimumJump(arr,i,r);
        if(jumps!=INT_MAX && jumps+1<mini) mini=jumps+1;
    }

    return mini;
}

int main()
{
    int arr[]={1,3,5,8,9,2,6,7,6,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<minimumJump(arr,0,n-1);
    return 0;
}
