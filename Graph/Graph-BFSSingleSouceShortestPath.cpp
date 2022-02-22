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
		map<T, int> dist;
		queue<T> q;

		for(auto a:l)
		{
			T v = a.first;
			dist[v] = INT_MAX;
		}

		q.push(src);
		dist[src] = 0;

		while(!q.empty())
		{
			T v = q.front();
			q.pop();
			for(auto nbr: l[v])
			{
				if(dist[nbr] == INT_MAX)
				{
					q.push(nbr);
					dist[nbr] = dist[v]+1;
				}
			}
		}

		for(auto a: l)
		{
			T v = a.first;
			cout<<"Vertex "<<v<<" Distance from source "<<dist[v]<<endl;
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