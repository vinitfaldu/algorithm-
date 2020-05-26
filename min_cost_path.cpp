#include<iostream>
using namespace std;

int min(int x,int y)
{
	return x < y ? x : y;
}

void mcp(int arr[][4],int n,int m)
{
	int i,j;

	int t[n][m];

	t[0][0]=arr[0][0];
	for(i=1;i<n;i++)
		t[i][0] = t[i-1][0] + arr[i][0];

	for(j=1;j<m;j++)
		t[0][j] = t[0][j-1] + arr[0][j];

	for(i=1;i<n;i++)
	{
		for(j=1;j<m;j++)
		{
			if(arr[i-1][j] > arr[i][j-1])
			{
				t[i][j] = arr[i][j] + t[i][j-1]; 
			}
			else
			{
				t[i][j] = arr[i][j] + t[i-1][j];
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

	cout<<"Min Cost: "<<t[n-1][m-1]<<endl;

	cout<<"_____Min Cost Path_____"<<endl;
	i=n-1; j=m-1;
	while(i>=0 && j>=0)
	{
		cout<<arr[i][j]<<"<-";
		if(t[i-1][j] > t[i][j-1])
		{
			j--;
		}
		else
		{
			i--;
		}

	}
	cout<<endl;

}
int main()
{
	int arr[][4]={{1,3,5,8},{4,2,1,7},{4,3,2,3}};
	int n=sizeof(arr)/sizeof(arr[0]);
	int m=sizeof(arr[0])/sizeof(arr[0][0]);

	mcp(arr,n,m);

	return 0;
}