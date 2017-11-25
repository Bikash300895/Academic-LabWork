#include <iostream>
using namespace std;

class Point
{
private:
    int mx,my,mz;
public:
    Point(int x=0, int y=0, int z=0):mx(x),my(y),mz(z)
    {

    }

    friend ostream& operator<< (ostream &out, const Point &point);
    friend istream& operator>> (istream &in, Point &point);
};

ostream& operator<< (ostream &out, const Point &point)
{
    out<<point.mx<<" "<<point.my<<" "<<point.mz;
    return out;
}

istream& operator>> (istream &in, Point &point)
{
    in>>point.mx;
    in>>point.my;
    in>>point.mz;
    return in;
}

int main()
{
    Point point;
    cin>>point;
    cout<<point;
    return 0;
}
