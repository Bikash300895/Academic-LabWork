#include <iostream>
#include <set>
using namespace std;

int main()
{
    multiset<string> cities{"Dhaka","Khulna","New Work","Chicago" };

    for(auto const& city:cities)
    {
        cout<<city<<" ";
    }
}
