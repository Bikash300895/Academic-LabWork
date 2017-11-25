#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

class Person
{
    string fn;
    string ln;
public:
    Person(string f, string l)
    {
        fn=f;
        ln=l;
    }
    string firstname() const
    {
        return fn;
    }
    string lastname() const
    {
        return ln;
    }
    void print()
    {
        cout<<fn<<" "<<ln<<endl;
    }
};

bool personSortCriterion(const Person& p1, const Person& p2)
{
    return p1.lastname()<p2.lastname() || (p1.lastname()==p2.lastname() && p1.firstname()<p2.firstname());
}

int main()
{
    vector<Person> coll;
    Person p1("bikash","roy");
    Person p2("sneha","paul");
    coll.push_back(p1);
    coll.push_back(p2);

    sort(coll.begin(), coll.end(), personSortCriterion);

    for(auto i: coll)
    {
        i.print();
    }
}
