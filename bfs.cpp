#include<iostream>
#include<list>
#include<queue>
#include<bitset>
#include<string>
using namespace std;

vector<int> adj[10];
bool visited[10];

void bfs(int s)
{
	queue<int> q;
	q.push(s);
	visited[s]=true;
	

	while(!q.empty())
	{
		int p=q.front();
		cout<<p<<" ";
		q.pop();
		for(int i=0;i<adj[p].size();i++)
		{
			if(visited[adj[p][i]]==false)
			{
				//cout<<" @"<<adj[p][i]<<"@ ";
				visited[adj[p][i]]=true;
				q.push(adj[p][i]);
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

		adj[x].push_back(y);					//make list...
		adj[y].push_back(x);
	}	

	initialize();

	bfs(4);		
	
	return 0;
}