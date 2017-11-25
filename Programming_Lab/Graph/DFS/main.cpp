/*#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector <int> adj[100];
int edge_id[100];
int vis[100];
void dsf(int s, int n)
{
    for(int i=0; i<100; i++) edge_id[i]=vis[i]=0;
    stack <int> S;
    S.push(s);

    while(1)
    {
        int u=S.top();
        S.pop();
        while(edge_id[u]<adj[u].size())
        {
            int v=adj[u][edge_id[u]];
            edge_id[u]++;
            if(vis[v]==0)
            {
                vis[v]=1;
                S.push(u);
                S.push(v);
                break;
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
    dsf(0,6);
    return 0;
}*/

#include<iostream>
#include<algorithm>
#include <list>

using namespace std;

class Graph
{
    int v;
    list <int> *adj;
    void DSFUtil(int v, bool visited[]);
public:
    Graph(int v);
    void addEdge(int v, int w);
    void DSF(int v);
};

Graph::Graph(int v)
{
    this->v=v;
    adj=new list<int>[v];
}

void Graph:: addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::DSFUtil(int v, bool visited[])
{
    visited[v]=true;
    cout<<v<<" ";

    list<int>:: iterator i;
    for(i=adj[v].begin(); i!=adj[v].end(); i++)
    {
        if(!visited[*i])
        {
            DSFUtil(*i, visited );
        }
    }
}

void Graph::DSF(int v)
{
    bool *visited=new bool[v];
    for(int i=0; i<v; i++)
        visited[i]=false;

    DSFUtil(v, visited );
}


int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Depth First Traversal\n";
    g.DSF(2);

    return 0;

}
