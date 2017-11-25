#include <iostream>
#include <map>
#include <cstring>
#include <queue>
using namespace std;

map<string,int> M;

void generate()
{
    queue<string> q;
    for(char c='a'; c<='z'; c++)
        q.push(string(1,c));
    string s;
    int num=1;
    while(!q.empty())
    {
        s=q.front();
        q.pop();
        M[s]=num;
        num++;

        if(s.size()==5) continue;
        for(char c=s[s.size()-1]+1; c<='z'; c++) q.push(s+c);
    }
}

int main()
{
    generate();
    string s;
    map<string,int>::iterator it;

    while(cin>>s)
    {
        it=M.find(s);
        if(it==M.end()) cout<<0<<endl;
        else cout<<it->second<<endl;
    }
}
