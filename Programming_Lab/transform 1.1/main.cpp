#include <iostream>
#include <vector>
#include <iterator>
#include <set>
#include <algorithm>
using namespace std;

int cube(int x)
{
    return x*x*x;
}

int main()
{
    set<int> coll;
    for(int i=0; i<9; i++)
        coll.insert(i);
    vector<int> coll2;

    cout<<"Before: ";
    copy(coll.begin(), coll.end(), ostream_iterator<int>(cout," "));
    cout<<endl;

    transform(coll.begin(), coll.end(), back_inserter(coll2), [](double d){return d*d*d;});
    cout<<"After:  ";
    copy(coll2.begin(), coll2.end(), ostream_iterator<int>(cout," "));
    cout<<endl;

}
