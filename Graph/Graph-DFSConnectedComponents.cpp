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

	void dfs()
	{
		map<T, bool> vis;
		queue<T> q;

        for(auto a: l)
        {
        	vis[a.first] = false;
        }

        
        int cnt = 1;
        for(auto a: l)
        {
        	if(!vis[a.first])
			{
				cout<<"Component "<<cnt<<": ";
				dfsRecursion(a.first, vis);
				cnt++;
				cout<<"\n";
			}
        }
	}
};

int main()
{
	Graph<string> g;
	g.addEdge("A", "B");
	g.addEdge("A", "D");
	g.addEdge("B", "D");
	g.addEdge("C", "D");
	g.addEdge("E", "F");
	g.addEdge("F", "H");
	g.addEdge("G", "I");
	g.dfs();
	return 0;
}