#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> adj[10];   						//one type of list...
bool visited[10];

void dfs(int s)
{
	visited[s]=true;
	cout<<s<<" ";

	for(int i=0;i<adj[s].size();i++)
	{
		//cout<<adj[s].size()<<"#"<<adj[s][i]<<" ";
		if(visited[adj[s][i]]==false)
		{	
		//	cout<<i+1<<"recursion";
			dfs(adj[s][i]);     
		}
	}
	//cout<<endl;
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

		adj[x].push_back(y);					//make list...
		adj[y].push_back(x);
	}	

	/*for(i=0;i<edges;i++)
	{
		for(j=0;j<adj[i].size();j++)
		{
			cout<<adj[i][j]<<" ";
		}
		cout<<endl;
	}*/

	initialize();

	dfs(4);						//  which is choose starting node write down in dfs(__)...
		

	return 0;
}