#include<iostream>
#include<list>
#include<stack>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int nodes,edges,x,y,i,j,p;
														// dfs logic using topological sort...
	cout<<"How Many Nodes :";
	cin>>nodes;

	cout<<"How Many Edges :";
	cin>>edges;

	vector<int> adj[nodes];
	bool visited[nodes];

	for(i=0;i<edges;i++)
	{
		cout<<"Enter "<<i+1<<" Edge"<<endl;
		cin>>x>>y;

		adj[x].push_back(y);     		// directed graph
	}

	stack<int> s;
	s.push(2);
	visited[2]=true;

//int a[nodes];
	while(!s.empty())
	{
		int t = s.top();
		//a[]
		//s.pop();
		//visited[t]=true;
		//cout << "t :" << t << endl;
	  	for(i=0;i<adj[t].size();i++)
		{
			if(visited[adj[t][i]]==false)
			{
				//cout << " Next :"<< adj[t][i] << endl;
				visited[adj[t][i]]=true;
				s.push(adj[t][i]);
				break;
			}
		}

		//cout << s.top() << ":" << t << endl;
		int v=s.top();
		if(v == t)
		{
			cout << t << " ";
			s.pop();
		}
	}
	return 0;
}







