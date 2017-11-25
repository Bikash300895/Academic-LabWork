#include <iostream>
#include <deque>
using namespace std;

void Lis(int arr[],int n)
{
    int lis[n];
    for(int i=0; i<n; i++)
        lis[i]=1;

    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(arr[i]>arr[j] && lis[i]<lis[j]+1)
                lis[i]=lis[j]+1;
        }
    }

    int max=1;
    for(int i=0; i<n; i++)
    {
        if(lis[i]>max)
            max=lis[i];
    }

    cout<<max<<endl;

    int tmp = max;
    deque<int> indexes;
    for( int i = n - 1; i >= 0; --i )
        if( lis[ i ] == tmp )
        {
            indexes.push_front( arr[i] );
            --tmp;
        }
    for(int i:indexes)
        cout<<i<<" ";

}

int main()
{
    int arr[]= {10, 22, 9, 33, 21, 50, 41, 60, 80};
    int n=9;
    Lis(arr,n);
}
