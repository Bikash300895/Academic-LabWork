#include <iostream>
#include <vector>
using namespace std;

template <typename T>
inline void printElement(const T& coll, const string& optstr="")
{
    cout<<optstr;
    for(const auto& elem: coll)
    {
        cout<<elem<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> coll;
    for(int i=0; i<10; i++)
        coll.push_back(i);

    printElement(coll, "all elements: ");
}
