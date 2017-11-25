#include <iostream>

using namespace std;

int main()
{
    int n=2;
    int sum=0;
    int a[3][2]={{1,2},
                 {3,4},
                 {5,6}};
    int b[2][3]={{1,2,3},
                 {4,5,6}};
    int c[3][3];

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            for(int k=0; k<2; k++)
            {
                sum+=a[i][k]*b[k][j];
            }
            c[i][j]=sum;
            sum=0;
        }
    }

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
