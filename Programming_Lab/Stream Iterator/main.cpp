#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<string> coll;

    copy(istream_iterator<string>(cin), istream_iterator<string>(), back_inserter(coll));

    unique_copy(coll.begin(),coll.end(),ostream_iterator<string>(cout,"\n"));
}
