#include<iostream>
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
void mssm(int n,int m,int arr[][5])
{
	int i,j;
	int t[n+1][m+1];

	for(i=0;i<n+1;i++)
	{
		for(j=0;j<m+1;j++)
		{
			t[i][j]=0;
		}
	}

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
}
int main()
{
	
	int arr[][5]={{0,0,1,1,1},{1,0,1,1,1},{0,1,1,1,1},{1,0,1,1,1}};
	int row=sizeof(arr)/sizeof(arr[0]);
	int column=sizeof(arr[0])/sizeof(arr[0][0]);

	mssm(row,column,arr);

	return 0;
}