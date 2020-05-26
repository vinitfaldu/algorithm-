#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int min(int x,int y,int z)
{
	if(x>=y)
	{
		return y < z ? y : z;
	}
	else
	{
		return x < z ? x : z;
	}
}
void mssm(vector<vector<int > > arr)
{
    int n = arr.size();
    int m = arr[0].size();
	int i,j;
	vector<vector<int > > t(n+1,vector<int>(m+1,0));

	int max_size=INT_MIN;
	for(i=1;i<n+1;i++)
	{
		for(j=1;j<m+1;j++)
		{
			if(arr[i-1][j-1]==0)
			{
				t[i][j]=0;
			}
			else
			{
				t[i][j]=1+min(t[i-1][j],t[i][j-1],t[i-1][j-1]);
				if(max_size<t[i][j])
				{
					max_size=t[i][j];
				}
			}
		}
	}

	for(i=0;i<n+1;i++)
	{
		for(j=0;j<m+1;j++)
		{
			cout<<t[i][j]<<" ";
		}
		cout<<endl;
	}

	cout<<"Maximum Size of Square Matrix is "<<max_size<<endl;
}
int main()
{
	
	vector<vector<int > > arr{{0,0,1,1,1},{1,0,1,1,1},{0,1,1,1,1},{1,0,1,1,1}};

	mssm(arr);

	return 0;
}