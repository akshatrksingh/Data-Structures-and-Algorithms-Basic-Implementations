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

	void bfs(T src)
	{
		map<T, bool> vis;
		queue<T> q;
		q.push(src);
		vis[src] = true;

		while(!q.empty())
		{
			T v = q.front();
			q.pop();
			cout<<v<<" ";
			for(auto nbr: l[v])
			{
				if(!vis[nbr])
				{
					q.push(nbr);
					vis[nbr] = true;
				}
			}
		}
	}
};

int main()
{
	Graph<string> g;
	g.addEdge("A", "B");
	g.addEdge("A", "D");
	g.addEdge("B", "C");
	g.addEdge("C", "D");
	g.bfs("A");
	return 0;
}