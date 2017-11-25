//SAME TAST USING CLASS CONCEPT

#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

class Pred
{
private:
    int x,y;
public:
    Pred(int xx, int yy):x(xx),y(yy){
    }
    bool operator()(int i) const
    {
        return i>x && i<y;
    }
};

int main()
{
    deque <int> coll={1,3,19,5,13,7,11,2,17};
    int x=5;
    int y=12;

    auto pos = find_if(coll.begin(), coll.end(),Pred(x,y));
    cout<<*pos<<endl;
}
