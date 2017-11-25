#include <iostream>
#include <map>
#include <vector>
#include <cstdio>

using namespace std;

int n;
vector<int> v;
map<int, int> m;

int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        if(m[n]==0) v.push_back(n);
        m[n]++;
    }

    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" "<<m[v[i]]<<endl;
    }
    return 0;
}
