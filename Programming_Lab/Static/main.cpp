#include <iostream>
using namespace std;

class something
{
    static int s;
    int m;
public:
    int getId() {return s++;}
};

int something::s=1;

int main()
{
    something first;
    something second;
    something third;

    cout<<first.getId()<<endl;
    cout<<second.getId()<<endl;
    cout<<third.getId()<<endl;
}
