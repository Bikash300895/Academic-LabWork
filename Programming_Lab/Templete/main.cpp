#include <iostream>

using namespace std;

template <class Type>
Type maxi(Type tx, Type ty)
{
    return (tx>ty)? tx: ty;
}
int main()
{
    cout<<maxi(5,6);
    return 0;
}
