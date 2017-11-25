#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <vector>
#define maxi 5000
#define INF 1000000000
using namespace std;

typedef struct all
{
	int first, second;
	int cost;
}E;


vector<E> V;
vector<E> ans;

class UnionFind
{
public:
	int Parent[maxi];
	int size;
public:
	void Intialize(int n)
	{
		for (int i = 0; i<n; i++)
			Parent[i] = i;
	}

	int findSet(int index)
	{
		return Parent[index] == index ? index : (Parent[index] = findSet(Parent[index]));
	}

	bool isEqual(int x, int y)
	{
		if (findSet(x) == findSet(y)) return true;
		else return false;
	}

	void Union(int x, int y, int z)
	{
		if (!isEqual(x, y))
        {
            Parent[findSet(x)] = findSet(y), size--;
            E a;
            a.first=x;
            a.second=y;
            a.cost=z;
            ans.push_back(a);
        }

	}

	int getSize()
	{
		return size;
	}
};

bool comp(const E &a, const E &b)
{
	return a.cost<b.cost;
}

int main()
{
	int node, edge;
	cin >> node >> edge;
	for (int i = 0; i < edge; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		V.push_back(E());
		V[i].first = a;
		V[i].second = b;
		V[i].cost = c;
	}

	sort(V.begin(), V.end(), comp);

	UnionFind X;
	X.Intialize(node);

	for (int i = 0; i < V.size() && X.getSize(); i++)
	{
		if (!X.isEqual(V[i].first, V[i].second))
		{
			X.Union(V[i].first, V[i].second, V[i].cost);
		}
	}

	for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i].first<<" "<<ans[i].second<<" "<<ans[i].cost<<endl;
    }
}
