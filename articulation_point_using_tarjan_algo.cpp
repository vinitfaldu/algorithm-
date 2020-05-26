#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<limits>
using namespace std;

const int MAX=1e4+5;
int nodes,edges,distTime[MAX],lowTime[MAX],parent[MAX];
bool visited[MAX],ap[MAX];
stack<int > s;
vector<int > adj[MAX];

int min(int x,int y)
{
	return x < y ? x : y;
}

void initially()
{
	for(int i=0;i<nodes;i++)
	{
		visited[i]=false;
		distTime[i]=-1;
		lowTime[i]=-1;
		parent[i]=-1;
		ap[i]=false;
	}
}

void apUtil(int u)
{
	static int t=0;
	int children=0;

	visited[u]=true;
	distTime[u]=lowTime[u]=t++;

	for(int i=0;i<adj[u].size();i++)
	{
		int vertex=adj[u][i];

		if(visited[vertex] == false)
		{
			children++;
			parent[vertex]=u;

			apUtil(vertex);

			lowTime[u] = min(lowTime[u],lowTime[vertex]);

			if(parent[u] == -1 && children >= 2)			// root node for condination
				ap[u]=true;							

			if(parent[u] != -1 && distTime[u] <= lowTime[vertex])	// visited time of node <= adj vertex of low time
				ap[u]=true;
		}
		else if(parent[u] != vertex)
		{
			lowTime[u]=min(lowTime[u],distTime[vertex]);
		}

	}
	

}

void articulationPoint()
{
	int i;

	initially();

	for(i=0;i<nodes;i++)
	{	
		if(visited[i]==false)
			apUtil(i);
	}

	for(i=0;i<nodes;i++)
	{
		cout<<"-----"<<i<<"-----"<<endl;;
		cout<<"visited Time:"<<distTime[i]<<" low Time:"<<lowTime[i]<<endl;
		cout<<"parent node is "<<parent[i]<<endl; 
	}

	//int count=0;
	cout<<"Articulation Point is : ";
	for(i=0;i<nodes;i++)
	{
		if(ap[i])
			cout<<i<<" ";
	}
}

int main()
{
	int x,y;

	cin>>nodes>>edges;

	for(int i=0;i<edges;i++)
	{
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	articulationPoint();

	cout<<endl;

	return 0;
}
/*
input
8
9
0
1
2
0
1
2
2
3
3
4
4
6
6
5
5
4
5
7
output
Articulation Point is : 2 3 4 5

input
5
5
1
0
0
2
2
1
0
3
3
4
output
Articulation Point is : 0 3

input
4
3
0
1
1
2
2
3
output
Articulation Point is : 1 2

input
7
8
0
1
1
2
2
0
1
3
1
4
1
6
3
5
4
5
output
Articulation Point is : 1
*/