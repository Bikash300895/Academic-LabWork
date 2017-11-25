#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct segment
{
    int L,R;
};

bool comp(const segment &s1, const segment &s2)
{
    return s1.L<s2.L;
}



int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<segment> s(1);
        while(cin>>s[0].L>>s[0].R, !(s[0].L==0&&s[0].R==0))
            s.push_back(s[0]);

        sort(s.begin()+1,s.end(),comp);
        int curL=0, rReach=0;
        size_t i=1;
        vector<segment> segments;
        while(rReach<m)
        {
            int newL=curL;
            size_t farthest=0;
            for( ;i<s.size(); ++i)
            {
                if(s[i].L>curL)
                    break;
                else if(s[i].R>newL)
                {
                    newL=s[i].R;
                    farthest=i;
                }
            }
            if(farthest==0) break;
            segments.push_back(s[farthest]);
            curL=rReach=newL;
        }
        if(rReach>=m)
        {
            cout<<segments.size()<<endl;
            for(i=0; i<segments.size(); ++i)
            {
                cout<<segments[i].L<<" "<<segments[i].R<<endl;
            }
        }
        else cout<<"0"<<endl;
        if(t) cout<<endl;
    }
    return 0;
}
