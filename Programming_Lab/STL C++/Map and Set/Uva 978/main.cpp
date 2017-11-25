#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int n,ng,nb,gs,bs,temp,b;
    priority_queue<int> green, blue;
    vector <int> gv, bv;

    cin>>n;
    while(n--)
    {
        cin>>b>>ng>>nb;
        while(ng--)
        {
            cin>>temp;
            green.push(temp);

        }
        while(nb--)
        {
            cin>>temp;
            blue.push(temp);
        }

        while(!green.empty()&& !blue.empty())
        {
            gs=green.size();
            bs=blue.size();
            temp=min(bs,gs);
            temp=min(temp,b);
            for(int i=0; i<temp; i++)
            {
                gs=green.top(); green.pop();
                bs=blue.top(); blue.pop();

                if(gs>bs) gv.push_back(gs-bs);
                else if(bs>gs) bv.push_back(bs-gs);
            }
            for(int i=0, sz=gv.size(); i<sz; i++) green.push(gv[i]);
            for( int i=0, sz=bv.size(); i<sz; i++) blue.push(bv[i]);
            gv.clear();
            bv.clear();
        }
        if (green.empty() && blue.empty())
        {
            cout << "green and blue died" << endl;
        }
        else if (blue.empty())
        {
            cout << "green wins" << endl;
            while (!green.empty())
            {
                cout << green.top() << endl; green.pop();
            }
        }
        else
        {
            cout << "blue wins" << endl;
            while (!blue.empty())
            {
                cout << blue.top() << endl; blue.pop();
            }
        }
        if (n)
            cout << endl;
        }
    return 0;
}
