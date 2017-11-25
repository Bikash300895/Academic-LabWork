#include <iostream>
using namespace std;

class A
{
public:
    //Must be public
    static int val; //Static mumber has only one copy for all object

};

//Has to be declared in this way
int A::val = 1;

int main()
{
    A a;
    cout<<a.val<<endl;
    return 0;
}
