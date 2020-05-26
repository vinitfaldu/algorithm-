/*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void twm(vector<vector<int>> arr)
{
	int i,j;
	int n=arr.size();
	int m=arr[0].size();
	vector<vector<int>> t(n,vector<int>(m,0));

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(i==0 || j==0)
			{
				t[i][j]=1;
			}
			else
			{
				t[i][j]=t[i-1][j]+t[i][j-1];
			}
		}
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cout<<t[i][j]<<" ";
		}
		cout<<endl;
	}

}

int main()
{
	vector<vector<int>> arr{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

	twm(arr);

	return 0;
}*/

#include<iostream>
using namespace std;

void total_ways_matrix(int n,int m,int arr[][4])
{
	int i,j;
	int t[n][m];

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(i==0 || j==0)
			{
				t[i][j]=1;
			}
			else
			{
				t[i][j]=t[i-1][j]+t[i][j-1];
			}
		}
	}

	/*for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cout<<t[i][j]<<" ";
		}
		cout<<endl;
	}*/

	cout<<"Total Ways "<<t[n-1][m-1]<<" to reach end point"<<endl;

}

int main()
{
	int arr[][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	int n=sizeof(arr)/sizeof(arr[0]);
	int m=sizeof(arr[0])/sizeof(arr[0][0]);

	total_ways_matrix(n,m,arr);

	return 0;
}


