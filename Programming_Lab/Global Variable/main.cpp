#include <iostream>
#include <typeinfo>
using namespace std;

int value(5);

int main()
{
    int value=10;
    {
        int value=15;
        //cout<<::value;
    }

    int  a(5);
    float b(4);
    std::cout << typeid(a + b).name() << " " << a + b << std::endl;
}
