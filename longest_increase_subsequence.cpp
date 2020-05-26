#include<iostream>
using namespace std;

int max(int x,int y)
{
	return (x>y) ? x : y;
}

int longINCsubstr(int arr[],int n)
{
	int i,j,m=0,val;
	int a[n];

	for(i=0;i<n;i++)
		a[i]=1;

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

	for(i=0;i<n;i++)
		if(m<a[i])
		{	
			m=a[i];
			//pos=i;
		}
		val=m;
		for(i=n-1;i>=0;i--)
		{
			if(a[i] == val)
			{
				cout<<arr[i]<<" ";
				val--;
			}
		}
	cout<<endl;
	return m;
}
int main()
{
	int arr[]={3,4,-1,0,6,2,3};
	int n=sizeof(arr)/sizeof(arr[0]);

	cout<<longINCsubstr(arr,n)<<endl;
	return 0;
}