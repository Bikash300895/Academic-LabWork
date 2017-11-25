#include<iostream>
#include<map>
#include<string>
#include<list>
#include<set>
#include<stack>
#include<queue>


using namespace std;

class Task
{
    public:
        static int cnt;
        string name;
        int prt;
        int tskcount;
        Task(){}
        Task(int prt, string name)
        {
            this->prt = prt;
            this->name = name;
            this->tskcount = cnt;
            cnt++;
        }
        void print() const
        {
            cout<<"priority : "<<prt <<" Name: "<<name<<" Count: "<<cnt<<endl;
        }
        bool operator < (const Task& P) const
        {
            if (this->prt > P.prt)
                return true;
            if (this->prt == P.prt)
            {
                if (this->tskcount > P.tskcount)
                    return true;
            }

            return false;
        }


};
int Task :: cnt = 0;
struct custom
{
    bool operator () (const int left,const int right) const
    {
        if(right <  left)
        {
//            if (right == left)
//                return true;
            return true;
        }
        return false;
    }
};

int main()
{
    stack<int, list<int> > s;
    s.push(12);
    s.push(13);
    s.push(15);
    s.push(8);
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    cout<<endl;
    priority_queue<int, vector<int>, custom> pq;
    //queue<int> pq;
    pq.push(12);
    pq.push(13);
    pq.push(15);
    pq.push(8);
    while(!pq.empty())
    {
        cout<<pq.top()<<endl;
        pq.pop();
    }
    cout<<"\n\n\n";
    priority_queue<Task> pqt;
    pqt.push(Task(10,"A"));
    pqt.push(Task(11,"X"));
    pqt.push(Task(11,"Y"));
    pqt.push(Task(11,"Z"));
    pqt.push(Task(7,"C"));
    pqt.push(Task(1,"A"));
    while(!pqt.empty())
    {
        pqt.top().print();
        pqt.pop();
    }
    return 0;
}
