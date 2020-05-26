#include<iostream>
using namespace std;

int max(int x,int y)
{
	return (x>y) ? x : y;
}

int longest_bitonic(int arr[],int n)
{
	int i,j,m=0,val;
	int a[n];
	int b[n];    //reverse direction for....

	for(i=0;i<n;i++)
	{	
		a[i]=1;
		b[i]=1;
	}

	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(arr[j]<arr[i])
			{
				a[i]=max(a[i],1+a[j]);
			}
		}
	}
	
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";

	cout<<endl;

	for(i=n-2;i>=0;i--)
	{
		for(j=n-1;j>i;j--)
		{
			if(arr[j]<arr[i])
			{
				b[i]=max(b[i],1+b[j]);
			}
		}
	}

	for(i=0;i<n;i++)
		cout<<b[i]<<" ";

	cout<<endl;

	for(i=0;i<n;i++)
	{
		a[i]=a[i]+b[i]-1;
		if(m<a[i])
		{	
			m=a[i];
			//pos=i;
		}
	}
	//cout<<endl;
	return m;
}
int main()
{
	int arr[]={2,-1,4,3,5,-1,3,2};
	int n=sizeof(arr)/sizeof(arr[0]);

	cout<<longest_bitonic(arr,n)<<endl;
	return 0;
}