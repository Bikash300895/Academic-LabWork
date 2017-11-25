#include <iostream>
using namespace std;

class Cents
{
    int m_cents;
public:
    Cents(int x)
    {
        m_cents=x;
    }
    int get_cents()
    {
        return m_cents;
    }
    Cents operator+(int value)
    {
        return Cents(m_cents+value);
    }
};

int main()
{
    Cents s1 = Cents(10);
    Cents s3=s1+15;
    cout<<s3.get_cents();
}
