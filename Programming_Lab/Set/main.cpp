#include <iostream>
#include <set>
#include <string>
using namespace std;

class Person
{
public:
    string name;
    int id;
    Person() {}

    Person(int id, string name )
    {
        this->id=id;
        this->name=name;
    }

    void print() const
    {
        cout<<"ID: "<<id<<" Name: "<<name<<endl;
    }

    bool operator< (const Person& P) const
    {
        if(this->id>P.id)
            return true;
        return false;
    }

    bool operator== (const Person& P) const
    {
        if(this->id == P.id)
            return true;
        return false;
    }
};

struct custom
{
    bool operator() (const Person& left, const Person& right)
    {
        if(right<left)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    set<Person,custom> s;
    s.insert(Person(102,string("Bikash")));
    s.insert(Person(115,string("Boka")));
    s.insert(Person(100,string("Idot")));

    set<Person>::iterator it=s.begin();
    while(it!=s.end())
    {
        it->print();
        it++;
    }
}
