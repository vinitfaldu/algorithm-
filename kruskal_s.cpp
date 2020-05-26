#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

const int MAX=1e4 + 5;
int nodes,edges;
int id[MAX];
pair<long long int,pair<int,int> > p[MAX];

void intialize()
{
	for(int i=0;i<nodes;i++)
		id[i]=i;
}

int root(int x)
{
	while(id[x] != x)
	{
		id[x]=id[id[x]];
		x=id[x];
	}
	return x;
}

void UpdateID(int x,int y)
{
	int p=root(x);
	int q=root(y);
	id[p]=id[q];
}

int kruskal(pair<long long int,pair<int,int> > p[])
{
	int i,j,minCost=0,x,y;

	for(i=0;i<edges;i++)
	{
		x=p[i].second.first;
		y=p[i].second.second;

		if(root(x) != root(y))
		{
			minCost += p[i].first;
			UpdateID(x,y);
			
			cout<<"Edge bitween "<<x<<"-"<<y<<" Weight :"<<p[i].first<<endl;
		
			/*for(j=0;j<nodes;j++)
			cout<<id[j]<<" ";

			cout<<endl;		*/
		}

		

	}

	return minCost;
}

int main()
{
	int minCost,i,x,y,weight;

	

	cin>>nodes>>edges;
	
	intialize();

	for(i=0 ; i<edges ; i++)
	{
		cin>>x>>y>>weight;
		p[i]=make_pair(weight,make_pair(x,y));
	}

	sort(p,p+edges);

	minCost = kruskal(p);

	cout<<"Total MinCost of Edges :"<<minCost<<endl;

	return 0;
}
/*
input
5
7
0
1
1
0
2
7
1
2
5
1
3
4
1
4
3
2
4
6
3
4
2

output

Edge bitween 0-1 Weight :1
Edge bitween 3-4 Weight :2
Edge bitween 1-4 Weight :3
Edge bitween 1-2 Weight :5
Total MinCost of Edges :11

input

9
14
0
1
4
0
7
8
1
7
11
1
2
8
7
8
7
7
6
1
2
8
2
8
6
6
2
3
7
2
5
4
6
5
2
3
5
14
3
4
9
5
4
10

output

Edge bitween 7-6 Weight :1
Edge bitween 2-8 Weight :2
Edge bitween 6-5 Weight :2
Edge bitween 0-1 Weight :4
Edge bitween 2-5 Weight :4
Edge bitween 2-3 Weight :7
Edge bitween 0-7 Weight :8
Edge bitween 3-4 Weight :9
Total MinCost of Edges :37
*/