#include <iostream>
#include <list>
using namespace std;

template <typename T>
void printElement(const T& coll)
{
    for(const auto& elem:coll)
        cout<<elem<<" ";
}

int main()
{
    list <char> coll;

    for(char c='a'; c<='z'; c++)
    {
        coll.push_back(c);
    }
    //printElement(coll);

    list<char>::const_iterator pos;
    for(pos=coll.begin(); pos!=coll.end(); pos++)
    {
        cout<<*pos<<" ";
    }
}
