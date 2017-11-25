#include <iostream>
#include "date.h"
using namespace std;

date::date(int d, int m, int y)
{
    setDate(d,m,y);
}

void date::setDate(int d, int m, int y)
{
    day=d;
    month=m;
    year=y;
}

void date::show()
{
    cout<<day<<"."<<month<<"."<<year;
}

int main()
{
    date d(2,3,2016);
    d.show();
    return 0;
}
