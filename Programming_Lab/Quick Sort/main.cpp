#include <iostream>
#include <algorithm>
using namespace std;

int A[6]={1,5,6,4,2,3};

int partition(int start, int end)
{
    int pivot=A[end];
    int index=start;
    for(int i=start; i<end; i++)
    {
        if(A[i]<pivot)
        {
            swap(A[i],A[index]);
            index++;
        }
        swap(A[end],A[index]);
    }
    return index;
}

void Quick_sort(int start, int end)
{
    if(start<end)
    {
        int partitionIndex=partition(start,end);
        Quick_sort(start,partitionIndex-1);
        Quick_sort(partitionIndex+1,end);
    }
}

int main()
{

    Quick_sort(0,5);
    for(int i=0; i<6; i++)
    {
        cout<<A[i]<<" ";
    }
    return 0;
}
