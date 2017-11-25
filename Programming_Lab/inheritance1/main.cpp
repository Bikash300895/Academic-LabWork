#include <iostream>
using namespace std;

class Base
{
public:
    int m_nValue;

    Base(int nValue=0):m_nValue(nValue)
    {
    }
};

class Derived: public Base
{
public:
    double m_dValue;

    Derived(double dValue=0.0, int nValue=0) : Base(nValue), m_dValue(dValue)
    {

    }

    void Print()
    {
        cout<<m_dValue<<endl<<m_nValue<<endl;
    }
};

int main()
{
    Derived cDerived(1.3,5);
    cDerived.Print();
}
