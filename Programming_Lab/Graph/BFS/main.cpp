#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[100];
int visited[100]={0};

void bsf(int s, int n)
{
    queue <int> q;
    q.push(s);
    visited[s]=1;
    cout<<s<<" ";

    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(int i=0; i<adj[u].size() ;i++)
        {
            if(visited[adj[u][i]]==0)
            {
                int v=adj[u][i];
                cout<<v<<" ";
                visited[v]=1;
                q.push(v);

            }
        }
    }
}

int main()
{
    adj[1].push_back(2);adj[2].push_back(1);
    adj[1].push_back(3);adj[3].push_back(1);
    adj[2].push_back(4);adj[4].push_back(2);
    adj[2].push_back(5);adj[5].push_back(2);
    adj[3].push_back(6);adj[6].push_back(3);
    bsf(5,5);
    return 0;
}
