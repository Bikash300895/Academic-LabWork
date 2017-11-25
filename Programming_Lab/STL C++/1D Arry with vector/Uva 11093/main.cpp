#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t,temp,n;
    cin>>t;
    for(int k=1; k<=t; k++)
    {
        cin>>n;
        vector<int> p,q;
        int i;
        for(i=0; i<n; i++)
        {
            cin>>temp;
            p.push_back(temp);
        }
        for(i=0; i<n; i++)
        {
            cin>>temp;
            q.push_back(temp);
        }
        bool found=false;

        for(i=0; i<n; i++)
        {
            bool ok=true;
            int pos=i;
            int petrol=0;

            for(int j=0; j<n; j++)
            {
                petrol+=p[pos];
                petrol-=q[pos];

                if(petrol<0)
                {
                    ok=false;
                    if(pos<i) i=n;
                    else i=pos;
                    break;
                }
                pos=(pos+1)%n;
            }

            if(ok)
            {
                found=true;
                cout<<"case "<<k<<": Possible from station "<<i+1<<endl;
                break;
            }
        }
        if(!found) cout<<"case "<<k<<": Not possible"<<endl;
    }
    return 0;
}


