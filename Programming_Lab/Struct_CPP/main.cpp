#include <iostream>
using namespace std;

struct Date
{
    int day;
    int month;
    int yr;
};

void print(Date &d)
{
    cout<<d.day<<"/"<<d.month<<"/"<<d.yr<<endl;
}

int main()
{
    Date d{9,4,2015};
    print(d);
    return 0;
}
