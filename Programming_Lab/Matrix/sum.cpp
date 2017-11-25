#include <cstdio>
using namespace std;

int main()
{
    int a[2][2]={1,2,3,4};
    int b[2][2]={1,2,3,4};
    int c[2][2];

    for(int i=0; i<4; i++)
    {
        *(c+i)=*(a+1)+ *(b+i);

    }
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            printf("%d",c[i][j]);
        }
    }
}
