#include<iostream>
using namespace std;

void dijkstra(int graph[][5],int n,int s)
{
	int i,j,count,minDistance,nextnode;
	int cost[n][n],distance[n],visited[n],prenode[n];

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(graph[i][j]==0)
			{
				cost[i][j]=9999;						// this INT_MAX again use then problem...
			}
			else
			{
				cost[i][j]=graph[i][j];
			}
		}
	}

	for(i=0;i<n;i++)
	{
		distance[i]=cost[s][i];
		visited[i]=0;
		prenode[i]=s;
	}
	distance[s]=0;
	visited[s]=1;
	count=1;

	while(count<n-1)
	{
		minDistance=9999;
		for(i=0;i<n;i++)
		{
			if(distance[i] < minDistance && !visited[i])
			{
				minDistance=distance[i];
				nextnode=i;
				//cout<<"min "<<minDistance<<endl;
			}
		}

		visited[nextnode]=1;

		for(i=0;i<n;i++)
		{
			if(!visited[i])
			{
				if(minDistance + cost[nextnode][i] < distance[i])
				{
					//cout<<"Dist: "<<distance[i]<<endl;;
					distance[i] = minDistance + cost[nextnode][i];
					prenode[i]=nextnode;

				}
			}
				
		}
	/*	cout<<"PreNode  :";
		for(i=0;i<n;i++)
		{
			cout<<prenode[i]<<" ";
			
		}
		cout<<"\nDistance :";
		for(i=0;i<n;i++)
		{
			cout<<distance[i]<<" ";
		}
			
		cout<<endl;*/
		count++;
	}

	for(i=0;i<n;i++)
	{
		if(i!=s)
		{
			cout<<"\nDistance of Node "<<i<<" :"<<distance[i];
			cout<<"\n Path="<<i;

			j=i;
			do{
				j=prenode[j];
				cout<<"<-"<<j;
			}while(j!=s);
		}
	}
}

int main()
{
	int graph[][5]={{0,1,0,3,10},
   					{1,0,5,0,0},
 				    {0,5,0,2,1},
   					{3,0,2,0,6},
   					{10,0,1,6,0}};

	int n=sizeof(graph)/sizeof(graph[0]);
	//int m=sizeof(graph[0])/sizeof(graph[0][0]);

	int source;

	cout<<"Which vertex make a source :";
	cin>>source;

	dijkstra(graph,n,source);

	return 0;
}