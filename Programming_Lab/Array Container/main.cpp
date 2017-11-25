#include <iostream>
#include <array>
#include <cstring>
using namespace std;

int main()
{
    const char *c="Test String";
    cout<<c<<endl;

    array<int,6> myary={1,2,3,4,5};
    //myary.fill(5);

    array<char,12>arr;
    for(auto it=myary.begin(); it!=myary.end(); it++)
        (*it) *= 2;
    for(auto it=myary.cbegin(); it!=myary.cend(); it++)
        cout<<*it<<endl;

    cout<<myary.max_size()<<endl;

    cout<<myary[4]<<endl;

    cout<<myary.data()<<endl;
    memcpy(arr.data(), c, 12);
    cout<<arr.data()<<endl;

    for(int &i:myary)
        cout<<i<<" ";
    return 0;
}
