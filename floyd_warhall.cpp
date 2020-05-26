#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

const int MAX=1e4 + 5;
int distance[MAX][MAX],path[MAX][MAX];

void floydWarshall(int n)
{
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(distance[i][j] > distance[i][k]+distance[k][j])
				{
					distance[i][j] = distance[i][k]+distance[k][j];
					path[i][j]=path[k][j];
				}
			}
		}
	}
}

int main()
{
	distance[][4]={{0,3,6,15},
					 {9999,0,-2,9999},
					 {9999,9999,0,2},
					 {1,9999,9999,0}};

	path[][4]={{-1,0,0,0}
			   {-1,-1,1,-1}
			   {-1,-1,-1,2}
			   {3,-1,-1,-1}};

	int n=sizeof(distance)/sizeof(distance[0]);		   

	floydWarshall(n);

	cout<<"*******Distance Matrix*******"<<endl;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<distance[i][j]<<"  ";
		}
		cout<<endl;
	}

	cout<<"******Path Matrix******"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<path[i][j]<<"  ";
		}
		cout<<endl;
	}


	return 0;
}