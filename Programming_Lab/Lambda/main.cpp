#include <iostream>
#include <string>
using namespace std;

int main()
{
    int x=0;
    int y=42;

    auto qqq=[=,&y] ()mutable
    {
        cout<<"x: "<<x<<endl;
        ++x;
        cout<<"y: "<<y<<endl;
        ++y;
    };
    x=y=77;
    qqq();
    qqq();
    cout<<"final: "<<x<<endl;
    cout<<"final: "<<y<<endl;
}
