#include <iostream>
#include <cstring>
using namespace std;

class Person
{
    string firstName;
    string lastName;
public:
    string firstName() const
    {
        return firstName;
    }
    string lastName()
    {
        return lastName;
    }
};

class PersonSortCriteria
{
public:
    bool operator() (const Person& p1, const Person& p2) const
    {
        return (p1.firstName()>p2.firstName() || (p1.firstName()>p2.firstName() && p1.lastName()>p2.lastName()))
    }
};

int main()
{
    set<Person, PersonSortCriteria> coll
}
