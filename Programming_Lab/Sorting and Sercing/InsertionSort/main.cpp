#include <iostream>
#include<string.h>

using namespace std;

void InsertionSort(int A[],int n)
{
    int i;
    for(i=1; i<n; i++)
    {
        int hole=i;
        int value=A[i];

        while(hole>0&&A[hole-1]>value)
        {
            A[hole]=A[hole-1];
            hole=hole-1;
        }
        A[hole]=value;
    }
}

int main()
{
    int A[5]={5,2,3,4,1};
    InsertionSort(A,5);
    for(int i=0; i<5 ;i++)
    {
        cout<<A[i]<<" ";
    }
}
