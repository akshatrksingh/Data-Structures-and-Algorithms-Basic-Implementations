#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph
{
	int v;
	//list<int> l[v]; // array of lists, but v not defined yet, so can't!! 
	list<int> *l;  //array of lists
public:
	Graph(int v)
	{
		this->v = v;
		l = new list<int>[v];
	}

	void addEdge(int x, int y)
	{
		l[x].push_back(y);
		l[y].push_back(x);
	}

	void printAdjList()
	{
		for(int i = 0; i < v; i++)
		{
			cout<<"vertex "<<i<<" is connected to ";
			for(int n: l[i])
			{
				cout<<n<<" ";
			}
			cout<<"\n";
		}
	}
};

int main()
{
	Graph g(5);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 4);
	g.addEdge(3, 4);
	g.printAdjList();
	return 0;
}