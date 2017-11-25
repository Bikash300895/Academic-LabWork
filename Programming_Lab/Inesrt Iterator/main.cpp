#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <deque>
#include <set>
using namespace std;

int main()
{
    list <int> coll1={1,2,3,4,5,6,7,8,9};

    vector<int> coll2;
    copy(coll1.cbegin(), coll1.cend(), back_inserter(coll2));
    for(int i:coll2)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    deque<int> coll3;
    copy(coll1.cbegin(), coll1.cend(), front_inserter(coll3));
    for(int i:coll3)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    set<int> coll4;
    copy(coll1.cbegin(), coll1.cend(), inserter(coll4,coll4.begin()));
    for(int i:coll4)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}
