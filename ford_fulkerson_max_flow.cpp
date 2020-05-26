#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>
#include<limits>
#include<string> 
using namespace std;
#define n 7
const int MAX=1e4+5;
//int n=MAX;
//int g[n][n];

int min(int x,int y)
{
	return x < y ? x : y;
}

bool bfs(int G[n][n],int s,int t,int parent[])
{
	queue<int > q;
	bool visited[n];
	memset(visited,0,sizeof(visited));		// 0 means false

	q.push(s);
	visited[s]=true;
	parent[s]=-1;

	while(!q.empty())
	{
		int curr=q.front();
		q.pop();
		
		for(int i=0;i<n;i++)
		{
			if(visited[i] == false && G[curr][i] > 0)
			{
				parent[i]=curr;
				q.push(i);
				visited[i]=true;
			}
		}
	}
	return (visited[t] == true);
}

int fordFulkerson(int g[n][n],int s,int t)
{
	int maxFlow=0,parent[n],G[n][n],i,j;
    //cout << "rr";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			G[i][j]=g[i][j];
	}

	while(bfs(G,s,t,parent))
	{
		int flow=MAX;
		for(i=t;i!=s;i=parent[i])
		{
			j=parent[i];							
			flow=min(flow,G[j][i]);		//mistake solve		j --> i
		}
		for(i=t;i!=s;i=parent[i])
		{
			j=parent[i];
			G[j][i] -= flow;			//mistake solve		j --> i
			G[i][j] += flow;			//mistake solve		j <-- i	
		}
		maxFlow += flow;
	}

	return maxFlow;
}

int main()
{	//int a;
	//cin>>a;
	//cout<<"@";

	int g[n][n]={{0,3,0,3,0,0,0},
				 {0,0,4,0,0,0,0},
				 {3,0,0,1,2,0,0},
				 {0,0,0,0,2,6,0},
				 {0,1,0,0,0,0,1},
				 {0,0,0,0,0,0,9},
				 {0,0,0,0,0,0,0}};

	cout<<"Max Flow in graph is "<<fordFulkerson(g,0,6)<<endl;

	return 0;
}
