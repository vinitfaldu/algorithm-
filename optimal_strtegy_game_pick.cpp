#include<iostream>
using namespace std;
/*int max(int x,int y)
{
	return x > y ? x : y;
}*/

void osgp(int arr[],int n)
{
	int i,j,k,l;
	int first[n][n],second[n][n];

	for(i=0;i<n;i++)
	{
		first[i][i]=arr[i];
		second[i][i]=0;
	}

	for(l=2;l<=n;l++)
	{
		for(i=0;i<n-l+1;i++)
		{
			j=i+l-1;
			if( (second[i+1][j]+arr[i]) > (second[i][j-1]+arr[j]) )
			{
				first[i][j]=second[i+1][j]+arr[i];
				second[i][j]=first[i+1][j];
			}
			else
			{
				first[i][j]=second[i][j-1]+arr[j];
				second[i][j]=first[i][j-1];
			}
		}
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<"("<<first[i][j]<<","<<second[i][j]<<")"<<"  ";
		}
		cout<<endl;
	}
}

int main()
{
	int arr[]={3,9,1,2};
	int n=sizeof(arr)/sizeof(arr[0]);

	osgp(arr,n);

	return 0;
}