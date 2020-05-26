#include<iostream>
using namespace std;

int getsum(int fr[],int i,int j)
{
	int sum=0;
	for(int x=i;x<=j;x++)
		sum+=fr[x];

	return sum;
}

int optBinarySearch(int arr[],int fr[],int n)
{
	int i,j,k,l;
	int a[n][n];

	for(i=0;i<n;i++)
		a[i][i]=fr[i];


	for(l=2;l<=n;l++)
	{
		for(i=0;i<=n-l;i++)
		{
			j=i+l-1;
			int sum=getsum(fr,i,j);

			a[i][j]=INT_MAX;
			for(k=i;k<=j;k++)
			{
				int val=sum + (k-1 < i ? 0 : a[i][k-1]) + (k+1 > j ? 0 : a[k+1][j]);
				if(val<a[i][j])
					a[i][j]=val;
			}

		}
	}
	/*for(i=0;i<n;i++)
	{	
		for(j=0;j<n;j++)
		{	
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}*/	

	return a[0][n-1];
}
int main()
{
	int input[]={10,12,16,21};
	int freq[]={4,2,6,3};
	int n=sizeof(input)/sizeof(input[0]);

	cout<<optBinarySearch(input,freq,n)<<endl;

}