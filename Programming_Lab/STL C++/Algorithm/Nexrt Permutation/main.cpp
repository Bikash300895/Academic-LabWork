#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a[]={1,2,3};
    sort(a,a+3);

    while(next_permutation(a,a+3))
    {
        for(int i=0; i<3 ;i++)
        {
            cout<<a[i];
        }
        cout<<endl;
    }
}
