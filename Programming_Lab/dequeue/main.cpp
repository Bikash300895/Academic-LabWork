#include <iostream>
#include <deque>
using namespace std;

void print(deque<int> q)
{
    deque<int>::iterator it;
    for(int i=0; i<q.size(); i++)
    {
        cout<<q[i]<<" ";
    }

    cout<<endl;
}

int main()
{
    int ar[]={1,2,3};
    deque<int> first;
    for(int i=0; i<5; i++)
    {
        int a;
        cin>>a;
        first.push_back(a);
        print(first);
    }

    return 0;
}
