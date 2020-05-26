// O(n)......time-complexity
#include<iostream>
using namespace std;
int max(int x,int y)
{
	return x > y ? x : y;
}

int mjre(int arr[],int n,int* p)
{
	int i,maxReach,jump,step;

	if(n<=1)
		return 0;

	if(arr[0]==0)
		return -1;

	maxReach=arr[0];  jump=1;  step=arr[0];

	//cout<<arr[0]<<" ";

	for(i=1;i<n;i++)
	{

		if(i == n-1)
			return jump;

		maxReach=max(maxReach,i+arr[i]);

		step--;

		if(step==0)
		{
			jump++;
			*(p++)=arr[i];
			//cout<<i<<" ";

			if(i>=maxReach)
				return -1;

			step = maxReach - i;
		}

	}



	return -1;
}

int main()
{
	int arr[]={2,3,1,1,2,4,2,0,1,1};
	int n=sizeof(arr)/sizeof(arr[0]);
	int *ptr;
//	cout<<n;

	int count=mjre(arr,n,ptr);
	cout<<"Number of jumps to reach end : "<<count<<endl;

	for(int i=0;i<count;i++)
		cout<<*(ptr+i)<<"-> ";

	cout<<endl;

	return 0;
}
