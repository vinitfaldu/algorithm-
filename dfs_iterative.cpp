#include<iostream>
#include<stack>
#include<vector>
#include<list>
#include<queue>
#include<bitset>
#include<string>
#include<bits/stdc++.h>
using namespace std;

vector<int> adj[10];   						//one type of list...
bool visited[10];

void dfs(int s)
{
	stack<int> ss;
	ss.push(s);
	visited[s]=true;

	while(!ss.empty())
	{
		int v = ss.top();
		cout<<v<<" ";
		ss.pop();

		for(int i=0;i<adj[v].size();i++)
		{
			if(visited[adj[v][i]]==false)
			{
				visited[adj[v][i]]=true;
				ss.push(adj[v][i]);
			}
		}
	}

}

void initialize()
{
	for(int i=0;i<10;i++)
		visited[i]=false;
}

int main()
{
	int nodes,edges,x,y,i,j;

	cout<<"HowMany Nodes(max 10) :";
	cin>>nodes;

	cout<<"HowMany Edges :";
	cin>>edges;
	
	for(i=0;i<edges;i++)
	{
		cout<<"Enter "<<i+1<<" Edge"<<endl;
		cin>>x>>y;
		
		//adj[y].push_back(x);
		adj[x].push_back(y);					//make list...
												//undirected graph..
	}	

	initialize();

	dfs(0);						//  which is choose starting node write down in dfs(__)...
		
	return 0;
}