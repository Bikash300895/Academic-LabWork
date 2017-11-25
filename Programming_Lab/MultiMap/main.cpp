#include <iostream>
#include <unordered_map>
using namespace std;

/*int main()
{
    multimap<int,string> coll;

    coll={ {3,"Bikash"}, {4,"Roy"}, {2,"is"}, {1,"This"}  };

    for(auto const& elem: coll)
    {
        cout<<elem.second<<" ";
    }
}
*/

int main()
{
    unordered_map<string,float> coll;
    coll["vat1"]=.16;
    coll["vat2"]=.07;
    coll["pi"]=3.1416;

    coll["vat1"]+=.04;

    for(auto const& elem: coll)
    {
        cout<<elem.second<<" "<<endl;
    }
}
