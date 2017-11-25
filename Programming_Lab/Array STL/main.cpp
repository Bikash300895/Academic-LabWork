#include <iostream>
#include <array>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    array<char,41> a;
    strcpy(&a[0],"Hello World");
    cout<<a.data()<<endl;
    printf("%s",a.data());



}
