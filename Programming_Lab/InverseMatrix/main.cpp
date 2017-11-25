#include <iostream>

using namespace std;

int main()
{
    int m,n;
    cout<<"Enter row and column: ";
    cin>>m>>n;
    int A[m][n];
    for(int i=0;i<m; i++)
    {
        for(int j=0; j<n ;j++)
        {
            cin>>A[i][j];
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<A[j][i]<<" ";
        }
        cout<<endl;
    }
}
