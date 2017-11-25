#include <iostream>
using namespace std;

class student
{
private:
    int marks;
public:
    student& setMarks(int m)
    {
        marks=m;
    }
    int getMarks()
    {
        return marks;
    }
    void print()
    {
        cout<<marks<<endl;
    }
};

int main()
{
    student s;
    s.setMarks(100).print();
}
