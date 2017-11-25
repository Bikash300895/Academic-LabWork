#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void print(int elem)
{
    cout<<elem<<" ";
}

int main()
{
    vector<int> coll;

    for(int i=0; i<10; i++)
        coll.push_back(i);

    for_each(coll.begin(), coll.end(), print);
    cout<<endl;
}
