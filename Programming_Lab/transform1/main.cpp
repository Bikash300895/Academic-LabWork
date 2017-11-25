#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <iterator>
#include "PRINT_ELEMENT.h"
using namespace std;

int square(int elem)
{
    return elem*elem;
}

int main()
{
    set<int> coll1;
    vector<int> coll2;

    for(int i=1; i<=9; i++)
    {
        coll1.insert(i);
    }
    PRINT_ELEMENT(coll1,"Initialized: ");

    transform(coll1.begin(), coll1.end(), back_inserter(coll2),square);
    PRINT_ELEMENT(coll2,"Squared: ");
}
