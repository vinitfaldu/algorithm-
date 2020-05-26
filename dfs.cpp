#include<iostream>
//#include<bits/stdc++.h>
#include<list>
using namespace std;

class graph{

	int v;

	list<int> *adj;

	void dfsuntil(int v,bool visited[]);

public:

	graph(int v);

	void addedge(int v,int w);

	void dfs(int v);
};

graph::graph(int v){

	this->v=v;
	adj = new list<int>[v];
}

void graph::addedge(int v,int w){

	adj[v].push_back(w);
}

void graph::dfsuntil(int v,bool visited[]){

	visited[v]=true;
	cout<<v<<" ";

	list<int>::iterator i;
	for(i=adj[v].begin(); i!=adj[v].end(); ++i)
		if(!visited[*i])
			dfsuntil(*i,visited); 
}

void graph::dfs(int v)
{
	bool *visited=new bool[v];
	for(int i=0;i<v;i++)
		visited[i]=false;

	dfsuntil(v,visited);
}

int main()
{
	graph g(4);
	g.addedge(0,1);
	g.addedge(0,2);
	g.addedge(1,2);
	g.addedge(2,0);
	g.addedge(2,3);
	g.addedge(3,3);

	cout<<"Following straing with 2 Vertex :"<<endl;

	g.dfs(2);
}