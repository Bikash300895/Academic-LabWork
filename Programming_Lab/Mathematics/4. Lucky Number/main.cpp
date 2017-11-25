#include <iostream>
using namespace std;

int isLucky(int n)
{
    static int counter =2;

    int next_position=n;
    if(counter>n) return 1;
    if(n%counter==0) return 0;

    next_position-=next_position/counter;
    counter++;

    return isLucky(next_position);
}

int main()
{
    cout<<isLucky(13);
}
