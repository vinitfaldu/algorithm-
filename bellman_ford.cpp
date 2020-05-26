#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

const int MAX=1e4 + 5;
pair<long long ,pair<int,int> > p[MAX];
int dist[MAX],parent[MAX],nodes,edges;

void initialy()
{
	for(int i=0;i<nodes;i++)
		dist[i]=99999;						// here you write down INT_MAX then infinity loop 
}

void bellmanFord(pair<long long,pair<int,int> > p[])
{
	int v,i,x,y,cost,check,flag=0;
	v=nodes;
	while(v!=0)								// v-1 times loop but v time after decrese distance 
	{										// that means graph in infinity loop avalable...
		for(i=0;i<edges;i++)
		{
			x=p[i].second.first;
			y=p[i].second.second;
			cost=p[i].first;
			if(dist[x]+cost < dist[y])
			{
				dist[y]=dist[x]+cost;
				parent[y]=x;							
			}
		}
		
		if(v==2)
			check=dist[1];				// i=1 not a source vertex...
		
		if(v==1)
		{
			if(check>dist[1])			// i check one distance their will be decrease means
			{	
				cout<<"Infinity loop avaliable in Graph...!!";
				flag=1;
			}
		}
		v--;
	}

	//v=nodes-1;
	//cout<<v;
	//cout<<"@"<<flag;
	if(flag==0)								// no infinity loop then graph's all vertex 
		for(i=1;i<nodes;i++)				// print min. distance ...
		{
			cout<<"\nDistance of Node "<<i<<"="<<dist[i];
			cout<<"\nPath :"<<i;

			v=i;
			do
			{
				v=parent[v];
				cout<<"<-"<<v;
			}while(v!=0);
		}

	cout<<endl;
/*	cout<<"vertex "<<" distance "<<" parent "<<endl;
	for(i=0;i<nodes;i++)
		cout<<i<<"      "<<dist[i]<<"         "<<parent[i]<<endl; */

}

int main()
{
	int i,x,y,weight,source;

	cin>>nodes>>edges>>source;

	initialy();
	dist[source]=0;						//0 as start vertex in Graph...
	parent[source]=0;      				// NULL means 0...

	for(i=0;i<edges;i++)
	{
		cin>>x>>y>>weight;				// x---->y directed graph...
		p[i]=make_pair(weight,make_pair(x,y));
	}

	bellmanFord(p);

	return 0;
}
/*
input

5
7
0
3
4
2
4
3
1
2
4
4
0
2
5
1
2
-3
0
3
8
0
1
4

output

Distance of Node 1=4
Path :1<-0
Distance of Node 2=1
Path :2<-1<-0
Distance of Node 3=6
Path :3<-4<-2<-1<-0
Distance of Node 4=5
Path :4<-2<-1<-0

input	(infinity loop)

4
4
0
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

*/