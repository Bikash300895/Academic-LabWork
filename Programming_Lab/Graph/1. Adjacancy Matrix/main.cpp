#include <iostream>
#include <list>
#include <stack>
using namespace std;

struct Graph
{
    int v;
    list<int> *adj;
public:
    Graph(int v);
    void addEdge(int v, int w);
};

Graph:: Graph(int v)
{
    this->v=v;
    adj=new list<int>[v];
}

Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}


