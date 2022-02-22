#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph
{
	map<T, list<T>> l;
public:
	void addEdge(T x, T y)
	{
		l[x].push_back(y);
		l[y].push_back(x);
	}

	void dfsRecursion(T src, map<T, bool> &vis)
	{
		cout<<src<<" ";
		 vis[src] = true;
		 for(T nbr: l[src])
		 {
		 	if(!vis[nbr])
		 	{
		 		dfsRecursion(nbr, vis);
		 	}
		 }
	}

	void dfs(T src)
	{
		map<T, bool> vis;
		queue<T> q;

        for(auto a: l)
        {
        	vis[a.first] = false;
        }

		dfsRecursion(src, vis);
	}
};

int main()
{
	Graph<string> g;
	g.addEdge("A", "B");
	g.addEdge("A", "D");
	g.addEdge("B", "D");
	g.addEdge("C", "D");
	g.dfs("A");
	return 0;
}