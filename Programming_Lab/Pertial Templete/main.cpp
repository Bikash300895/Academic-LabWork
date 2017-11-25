#include <iostream>
#include <cstring>
using namespace std;

template<typename T, int size>
class Buffer
{
    T ary[size];
public:
    T* GetBuffer()
    {
        return ary;
    }
    T& operator[] (int index)
    {
        return ary[index];
    }

};

template<typename T,int size>
void Print(Buffer<T,size> &buf)
{
    cout<<buf.GetBuffer();
}

int main()
{
    Buffer<char,10> B;
    strcpy(B.GetBuffer(),"Bikash");
    Print(B);
}
