#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph
{
	int v;
	unordered_map<string, list<pair<string, int>>>l;
public:

	void addEdge(string x, string y, bool bi, int w)
	{
		l[x].push_back(make_pair(y, w));
		if(bi)
		{
			l[y].push_back(make_pair(x, w));
		}
	}

	void printAdjList()
	{
		for(auto a: l)
		{
			string src_v = a.first;
			auto nbr = a.second;
			cout<<src_v<<":";
			for(auto nb: nbr)
			{
				string dst_v = nb.first;
				auto wt =  nb.second;
				cout<<dst_v<<" "<<wt<<", ";
			}
			cout<<"\n";
		}
	}
};

int main()
{
	Graph g;
	g.addEdge("A", "B", false, 59);
	g.addEdge("A", "C", true, 3);
	g.addEdge("B", "C", true, 14);
	g.addEdge("C", "D", false, 78);
	g.addEdge("A", "D", true, 254);
	g.printAdjList();
	return 0;
}