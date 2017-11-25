#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream out;
    out.open("output.txt");

    out<<"This is line 1"<<endl;
    return 0;
}
