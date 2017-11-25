#include <iostream>
#include<string>
using namespace std;

int A[10]={2,5,4,3,1}, temp[10];

void MergeSort(int lo, int hi)
{
    if(lo==hi) return;
    int mid=(lo+hi)/2;

    MergeSort(lo,mid);
    MergeSort(mid+1,hi);

    int i,j,k;
    for(i=lo,j=mid+1, k=lo; k<=hi; k++)
    {
        if(i==mid+1) temp[k]=A[j++];
        else if(j==hi+1) temp[k]=A[i++];
        else if(A[i]<A[j]) temp[k]=A[i++];
        else temp[k]=A[j++];
    }

    for(k=lo; k<=hi; k++)
    {
        A[k]=temp[k];
    }
}

int main()
{
    MergeSort(0,4);
    for(int i=0; i<5; i++)
    {
        cout<<A[i]<<" ";
    }
    return 0;
}
