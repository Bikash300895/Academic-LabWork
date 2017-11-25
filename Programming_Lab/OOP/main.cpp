#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        if(a==-1 && b==-1) break;
        int x=b-a;
        if(x<0) x=-x;
        int y=100-x;
        cout<<min(x,y)<<endl;
    }
    return 0;
}
