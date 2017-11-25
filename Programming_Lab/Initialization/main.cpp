#include <iostream>
using namespace std;

class Something
{
    const int a[5];
public:
    Something():a{5,4,3,2,1}
    {

    }
    void show()
    {
        for(int i=0;i<5; i++)
            cout<<a[i]<<endl;
    }
};

int main()
{
    Something A;
    A.show();
}
