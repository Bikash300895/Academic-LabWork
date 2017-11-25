#include <iostream>

using namespace std;

int main()
{
    int myAry[]={0,12,25,33,48,55,76};
    int item;
    cout<<"Enter number to search : ";
    cin>>item;
    int low=0,high=6,mid=0;
    while(low<=high && myAry[mid]!=item)
    {
        mid=(low+high)/2;
        if(myAry[mid]>item) high=mid-1;
        else low=mid+1;
    }
    cout<<mid;
    return 0;
}
