#include <iostream>
using namespace std;

template <typename T>
class Storage8
{
    T m_tType[8];
public:
    void Set(int nIndex, T &tType)
    {
        m_tType[nIndex] = tType;
    }

    T& Get(int nIndex)
    {
        return m_tType[nIndex];
    }
};

int main()
{
    Storage8<int> cIntStorage;

    for(int i=0; i<8; i++)
        cIntStorage.Set(i,i);
    for(int i=0; i<8; i++)
        cout<<cIntStorage.Get(i)<<endl;
}
