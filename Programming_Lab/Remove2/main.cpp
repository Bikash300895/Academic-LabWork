#include <iostream>
#include <iterator>
#include <algorithm>
#include <list>
using namespace std;

int main()
{
    list<int> coll;

    for(int i=0; i<=6; i++)
    {
        coll.push_back(i);
        coll.push_front(i);
    }

    cout<<"Pre:  ";
    copy(coll.begin(), coll.end(), ostream_iterator<int>(cout," "));
    cout<<endl;

    cout<<"Post: ";
    list<int>::iterator end = remove(coll.begin(), coll.end(), 3);
    copy(coll.begin(),end,ostream_iterator<int>(cout," "));
    cout<<endl;

    cout<<"Removed element: ";
    copy(end,coll.end(),ostream_iterator<int>(cout," "));
    cout<<endl;

    coll.erase(end, coll.end());

    cout<<"End:  ";
    copy(coll.begin(), coll.end(), ostream_iterator<int>(cout," "));
    cout<<endl;

}
