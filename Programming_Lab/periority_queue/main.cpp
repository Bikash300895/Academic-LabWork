#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <iomanip>
using namespace std;

class student
{
public:
    string name;
    double cg;
    int marks;
    int roll;
    static int r;

    student() {}
    student(string name, double cg, int marks)
    {
        this->name=name;
        this->cg=cg;
        this->marks=marks;
        roll=r;
        r++;
    }

    void print() const
    {
        cout<<setw(2)<<roll<<" "<<setw(10)<<name<<" "<<setw(7)<<cg<<" "<<setw(7)<<marks<<endl;
    }

    bool operator< (const student& s) const
    {
        if(this->cg<s.cg)
        {
            return true;
        }
        else if(this->cg==s.cg)
        {
            if(this->marks<s.marks)
                return true;
            return false;
        }
        return false;
    }
};

int student::r=1;

struct custom
{
    bool operator() (const int left, const int right)
    {
        if(right<left)
            return true;
        return false;
    }
};

int main()
{
    priority_queue<int, vector<int>, custom> q;
    q.push(5);
    q.push(4);
    q.push(3);
    q.push(1);
    q.push(2);

    while(!q.empty())
    {
        cout<<q.top()<<" ";
        q.pop();
    }
    cout<<endl<<endl;

    priority_queue<student> S;
    S.push(student("Putul",3.78,90));
    S.push(student("Bikash",3.36,75));
    S.push(student("BOKA",3.30,81));
    S.push(student("IDOT",3.36,85));

    while(!S.empty())
    {
        S.top().print();
        S.pop();
    }
}
