#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class PrintInt
{
public:
    void operator() (int elem)
    {
        cout<<elem<<" ";
    }
};

int main()
{
    vector <int> coll;

    for(int i=0; i<=9; i++)
        coll.push_back(i);

    for_each(coll.begin(), coll.end(), PrintInt());
    cout<<endl;
}
