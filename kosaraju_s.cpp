#include<iostream>
#include<vector>	//gitHub.com
#include<stack>		//https://www.youtube.com/watch?v=RpgcYiky7uw&list=PLrmLmBdmIlpu2f2g8ltqaaCZiq6GJvl1j&index=8
#include<algorithm>
#include<utility>
using namespace std;

const int MAX=1e4 + 5;
vector<int > adj[MAX];
vector<int > pre_adj[MAX];
//vector<int > components[MAX];
int edges,nodes,numComponent=0;//component[MAX];
bool visited[MAX];
stack<int> s;

void initialy()
{
	for(int i=0;i<edges;i++)
		visited[i]=false;
}

void kosaraju_dfs_1(int x)
{
	visited[x]=true;
	for(int i=0;i<adj[x].size();i++)
		if(!visited[adj[x][i]])
			kosaraju_dfs_1(adj[x][i]);

	s.push(x);	

}

void kosaraju_dfs_2(int x)
{
	cout<<x<<" ";
	visited[x]=true;
	//component[x]=numComponent;
	//components[numComponent].push_back(x);

	for(int i=0;i<pre_adj[x].size();i++)
		if(!visited[pre_adj[x][i]])
			kosaraju_dfs_2(pre_adj[x][i]);


}

void kosaraju()
{
	for(int i=0;i<nodes;i++)
	{
		if(!visited[i])
			kosaraju_dfs_1(i);
	}

	initialy();

	while(!s.empty())
	{
		int v=s.top();
		s.pop();

		if(!visited[v])
		{
			cout<<"Component :"<<(numComponent+1)<<endl;;
			kosaraju_dfs_2(v);
			numComponent++;
			cout<<endl;
		}
	}
}
int main()
{	
	int i,x,y;

	cin>>nodes>>edges;

	initialy();

	for(i=0;i<edges;i++)
	{
		cin>>x>>y;

		adj[x].push_back(y);
		pre_adj[y].push_back(x);
	}

	kosaraju();

	cout<<"Total no of Components :"<<numComponent<<endl;

	return 0;
}
/*
input

11
13
2
0
0
1
1
2
1
3
3
4
4
5
5
3
6
5
6
7
7
8
8
9
9
6
9
10

output

Component :1
6 9 8 7 
Component :2
10 
Component :3
0 2 1 
Component :4
3 5 4 
Total no of Components :4
*/