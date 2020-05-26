#include<iostream>
using namespace std;

int max(int x,int y)
{
	return x > y ? x : y;
}

int weightJobSche(int arr[][3],int n)
{
	int i,j,m=INT_MIN;
	int a[n];

	for(i=0;i<n;i++)
		a[i]=arr[i][2];

	/*for(i=0;i<n;i++)
		cout<<a[i]<<" ";*/

//cout<<endl;
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(arr[i][0]>=arr[j][1])
			{
				a[i]=max(a[i],arr[i][2]+a[j]);
				if(m<a[i])
					m=a[i];
			}
		}
	}

	for(i=0;i<n;i++)
		cout<<a[i]<<" ";

	cout<<endl;

	return m;
}

int main()
{
	//enter finishing time sorted..
	int arr[][3]={{1,3,5},{2,5,6},{4,6,5},{6,7,4},{5,8,11},{7,9,2}};  //start,finish,profit....
	int n=sizeof(arr)/sizeof(arr[0]);

	cout<<weightJobSche(arr,n)<<endl;

	return 0;
} 