#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>				// my style using concept of tushar roy video contained...
#include<string>
using namespace std;

const int MAX=1e4+5;
bool visited[MAX];
int nodes,edges;
int g[MAX][MAX],parent[MAX],c[MAX][MAX];	// Globally inialize means value of all element is zero
vector<int > adj[MAX];

void initially()
{
	for(int i=0;i<nodes;i++)
		visited[i]=false;
}

int bfs(int sNode,int eNode)
{
	int min=MAX;//cout<<min;
	memset(parent,-1,sizeof(parent));
	initially();

	queue<int > q;
	q.push(sNode);
	visited[sNode]=true;
	//cout<<"@";
	while(!q.empty())
	{
		int current=q.front();
		q.pop();
		//cout<<"@";
		for(int i=0;i<adj[current].size();i++)
		{
			if(visited[adj[current][i]]==false && c[current][adj[current][i]] > 0)
			{
					if(min > c[current][adj[current][i]])
						min=c[current][adj[current][i]];

					parent[adj[current][i]]=current;

					if(adj[current][i] == eNode)
						return min;

					visited[adj[current][i]]=true;
					q.push(adj[current][i]);
				
			}
		}
	}

	return 0;
}

int edmondsKarp(int sNode,int eNode)
{
	int maxflow=0;

	while(true)
	{
		int flow=bfs(sNode,eNode);
		//cout<<flow;
		if(flow == 0)
		{
			break;
		}
		maxflow += flow;
		int current=eNode;

		while(current!=sNode)
		{
			int previous=parent[current];
			c[current][previous] += flow;
			c[previous][current] -= flow;
			current=previous;
		}
	}

	return maxflow;
}
int main()
{
	int weight,x,y,source,sink;

	cin>>nodes>>edges;

	cin>>source>>sink;

	for(int i=0;i<edges;i++)
	{
		
		cin>>x>>y>>weight;
		c[x][y]=weight;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	int maxflow=edmondsKarp(source,sink);

	cout<<"Max Flow in Graph is "<<maxflow<<endl;

	return 0;
}
/*
input
5
6
0
4
0
1
2
0
2
3
1
4
3
2
1
1
2
3
1
3
4
3
output
Max Flow of Garph is 4

input
7
11
0
6
0
3
3
2
0
3
0
1
3
2
3
1
1
2
4
4
1
1
2
4
2
3
4
2
3
5
6
4
6
1
5
6
9

output
Max Flow in Graph is 5
*/


