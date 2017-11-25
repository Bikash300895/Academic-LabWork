#include <iostream>

using namespace std;

class IntList
{
    int m_list[10];
public:
    int& operator[] (int index)
    {
        return m_list[index];
    }
};

int main()
{
    IntList l;
    l[5]=2;
    cout<<l[5];
    return 0;
}
