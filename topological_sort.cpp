#include<iostream>
#include<list>
#include<queue>
using namespace std;
int main()
{
	int nodes,edges,x,y,i,j,p;
														// bfs logic using topological sort...
	cout<<"How Many Nodes(max 10) :";
	cin>>nodes;

	cout<<"How Many Edges :";
	cin>>edges;

	vector<int> adj[nodes];
	bool visited[nodes];
	int degree[nodes];

	for(i=0;i<edges;i++)
	{
		cout<<"Enter "<<i+1<<" Edge"<<endl;
		cin>>x>>y;

		adj[x].push_back(y);     		// directed graph
	}

	for(i=0;i<nodes;i++)
		degree[i]=0;

	for(int i=0;i<nodes;i++)
	{	
		visited[i]=false;
		for(j=0;j<adj[i].size();j++)
		{
			//cout<<adj[i][j]<<" ";
				degree[adj[i][j]] = degree[adj[i][j]] + 1;
		}
		//cout<<endl;
	}	
//for(i=0;i<nodes;i++)
//	cout<<degree[i]<<" ";

	queue<int> q;

	for(i=0;i<nodes;i++)
		if(degree[i] == 0)
		{	
			q.push(i);
			visited[i] = true;
		}

		while(!q.empty())
		{
			 p = q.front();
			 cout<<p<<" ";
			 q.pop();

			 for(j=0;j<adj[p].size();j++)
			 {
			 		if(visited[adj[p][j]] == false)
			 		{
			 			degree[adj[p][j]] = degree[adj[p][j]] - 1;
			 			
			 			if(degree[adj[p][j]] == 0)
			 			{
			 				q.push(adj[p][j]);
			 				visited[adj[p][j]] = true;
			 			}
			 		}
			 }
		}


	return 0;
}




