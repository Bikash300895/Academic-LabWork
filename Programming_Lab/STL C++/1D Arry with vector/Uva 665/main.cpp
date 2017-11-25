#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct weight_in
{
    set<int> left;
    set<int> right;
    char result;
};

bool can_be(int coin, const vector<weight_in> &weight_ins)
{
    bool result=false;
    for(int i=0; i<weight_ins.size(); i++)
    {
        if(weight_ins[i].left.find(coin)!=weight_ins[i].left.end())
        {
            if(weight_ins[i].result == '=') return false;
            else result=true;
        }
        else if(weight_ins[i].right.find(coin)!=weight_ins[i].right.end())
        {
            if(weight_ins[i].result == '=') return false;
            else result=true;
        }
        else
        {
            if(weight_ins[i].result != '=') return false;
        }
    }
    return result;
}

int main()
{
    int n,k,p,coin,i;
        cin>>n>>k;
        vector<weight_in> weight_ins;
        set<int> coins_used;

        while(k--)
        {
            cin>>p;
            weight_in tmp;
            for(i=0; i<p; i++)
            {
                cin>>coin;
                coins_used.insert(coin);
                tmp.left.insert(coin);
            }
            for(i=0; i<p; i++)
            {
                cin>>coin;
                coins_used.insert(coin);
                tmp.right.insert(coin);
            }
            cin>>tmp.result;

            weight_ins.push_back(tmp);
        }
        vector<int> suspects;
        for(i=0 ;i<n ;i++)
        {
            if(can_be(i,weight_ins))
                suspects.push_back(i);
        }
        if(suspects.empty())
        {
            for(i=0; i<n ;i++)
            {
                if(coins_used.find(i)==coins_used.end() )
                    suspects.push_back(i);
            }
        }

        if(suspects.size()==1) cout<<suspects[0]<<endl;
        else cout<<0<<endl;
    return 0;
}
