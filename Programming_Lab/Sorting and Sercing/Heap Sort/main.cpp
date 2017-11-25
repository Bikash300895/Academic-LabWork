#include <iostream>
#include <stdio.h>

#define SWAP(arr, a, b) \
  do { \
    int tmp = arr[a]; \
    arr[a] = arr[b]; \
    arr[b] = tmp; \
  } while (0)


using namespace std;
/*int LEFT(int i)
{
    return 2*i;
}

int RIGHT(int i)
{
    return 2*i+1;
}*/

void MAX_HEAPIFY(int A[],int i)
{
    int largest;
    int l=2*i;
    int r=2*i+1;
    if(l<=10 && A[l]>A[i])
    {
        largest=l;
    }
    else if(r<=10 && A[r]>A[largest])
    {
        largest=r;
    }
    else largest=i;

    if(largest!=i)
    {
        int temp=A[i];
        A[i]=A[largest];
        A[largest]=temp;
        MAX_HEAPIFY(A,largest);
    }
}

void heapify(int arr[], int i)
{
    int lft = i * 2;
    int rgt = lft + 1;
    int grt = i;

    if (lft <= 10 && arr[lft] > arr[grt]) grt = lft;
    if (rgt <= 10 && arr[rgt] > arr[grt]) grt = rgt;
    if (grt != i) {
        SWAP(arr, i, grt);
        heapify(arr, grt);
    }
}

int main()
{
    int A[]={0,3,14,10,8,7,9,16,2,4,1};
    heapify(A,11);
    int i;
    for(i=1; i<11; i++)
    {
        cout<<A[i]<<" ";
    }
}
