#include<iostream>
#include<vector>
//#include<pair>
#include<algorithm>
#include<utility>
using namespace std;

const int MAX=1e4 + 5;
typedef pair<long long,int > PI;
vector<PI > adj[MAX];
int nodes,edges;

void floydWarshall()
{
	int distance[nodes][nodes],path[nodes][nodes];
	int i,j,k,x,y;

	for(i=0;i<nodes;i++)
	{
		for(j=0;j<nodes;j++)
		{	
			if(i==j)
				distance[i][j] = 0;
			else
				distance[i][j]=9999;


			path[i][j]=-1;
		}
	}

	for(i=0;i<nodes;i++)
	{
		for(j=0;j<adj[i].size();j++)
		{
			x=adj[i][j].second;
			y=adj[i][j].first;

			distance[i][x]=y;
			path[i][x]=i;
		}
	}

/*for(i=0;i<nodes;i++)
	{
		for(j=0;j<nodes;j++)
		{
			cout<<path[i][j]<<"  ";
		}
		cout<<endl;
	}*/

	for(k=0;k<nodes;k++)
	{
		for(i=0;i<nodes;i++)
		{
			for(j=0;j<nodes;j++)
			{
				if(distance[i][j] > distance[i][k]+distance[k][j])
				{
					distance[i][j] = distance[i][k]+distance[k][j];
					path[i][j]=path[k][j];
				}
			}
		}
	}

	cout<<"\n**********Distance Matrix********"<<endl;
	for(i=0;i<nodes;i++)
	{
		for(j=0;j<nodes;j++)
		{
			cout<<distance[i][j]<<"  ";	//diagonal in negative that means infinity loop in graph... 
		}
		cout<<endl;
	}

	cout<<"\n**********Path Matrix********"<<endl;
	for(i=0;i<nodes;i++)
	{
		for(j=0;j<nodes;j++)
		{
			cout<<path[i][j]<<"  ";
		}
		cout<<endl;
	} 

}

int main()
{
	/*int distance[][4]={{0,3,6,15},
					 {9999,0,-2,9999},
					 {9999,9999,0,2},
					 {1,9999,9999,0}};

	int path[][4]={{-1,0,0,0},
			   {-1,-1,1,-1},
			   {-1,-1,-1,2},
			   {3,-1,-1,-1}};*/

	int i,x,y,weight;

	cin>>nodes>>edges;

	for(i=0;i<edges;i++)
	{
		cin>>x>>y>>weight;
		adj[x].push_back(make_pair(weight,y));
	}

	floydWarshall();

	return 0;
}

/*
input
4
6
0
3
15
3
0
1
0
1
3
0
2
6
2
3
2
1
2
-2

output

**********Distance Matrix********
0  3  1  3  
1  0  -2  0  
3  6  0  2  
1  4  2  0  

**********Path Matrix********
-1  0  1  2  
3  -1  1  2  
3  0  -1  2  
3  0  1  -1  

input	(infinity loop type graph)

4
4
0
1
1
1
2
3
2
3
2
3
1
-6

output

**********Distance Matrix********
0  0  3  5  
9998  -1  2  4  
9995  -4  -1  1  						diagonal in negative that means infinity loop in graph...
9992  -7  -4  -2  

**********Path Matrix********
-1  3  1  2  
-1  3  1  2  
-1  3  1  2  
-1  3  1  2  
*/