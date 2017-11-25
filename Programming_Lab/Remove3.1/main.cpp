//Program to erase associative container

#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
    set<int> coll = {1,3,2,4,5,6,7,8,9};

    copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(cout," "));
    cout<<endl;

    int num=coll.erase(3);
    cout<<"number of removed element: "<<num<<endl;
    copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(cout," "));
    cout<<endl;
}
