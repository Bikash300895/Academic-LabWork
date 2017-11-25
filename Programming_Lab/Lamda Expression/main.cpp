#include<bits/stdc++.h>
using namespace std;

struct isEven
{
    bool operator()(int x)
    {
        return !(x%2);
    }
};

class isMultipleOf
{
    int m_multi;
public:
    isMultipleOf(int multi): m_multi(multi){}
    bool operator()(int x)
    {
        return !(x%m_multi);
    }
};

int main()
{
    vector<int> col {1,2,3,4,5,9,8,7,6,10,15,18};
    int c;

    //This is the scenario without lamnda expression
    c = count_if(col.begin(), col.end(), isEven());
    cout<<"Number of even number: "<<c<<endl;

    //This is how to do this using lambda
    int d = count_if(col.begin(), col.end(), [](int x) {return !(x%2);}); //This is like an inline function
    cout<<"Number of even number: "<<d<<endl;

    //if we want to find which are multiple of a given nummber
    //process without lambda
    int multi = 5;
    int e = count_if(col.begin(), col.end(), isMultipleOf(multi));
    cout<<"Integer that are multiple of 5 : "<<e<<endl;

    //

    return 0;
}
