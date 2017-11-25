#include <iostream>
#include <stack>
#include <deque>
using namespace std;

int main()
{
    stack <int> s,q;
    for(int i=0; i<5; i++)
        s.push(i);
    cout<<s;
    return 0;
}
