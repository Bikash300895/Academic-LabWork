#include <iostream>

using namespace std;

int main()
{
    int arr[]={2,5,6,7,9,13,15,20,25,35};
    int n;cin>>n;
    int low=0,high=9,mid;
    while(low<=high)
    {
        mid=low+(high-low)/2;
        if(arr[mid]==n)
            {
                cout<<mid;
                break;
            }
        else if(arr[mid]<n)
            low=mid+1;
        else high=mid-1;
    }
}
