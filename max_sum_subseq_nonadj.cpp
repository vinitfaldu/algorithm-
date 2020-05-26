#include<iostream>
using namespace std;

int max(int x,int y)
{
	return x > y ? x : y; 
}

void msum_ss_nonadj(int arr[],int n)
{
	int i,rem,inclusive=arr[0],exclusive=0;

	for(i=1;i<n;i++)
	{
		rem=exclusive;
		exclusive=inclusive;
		inclusive=max(rem+arr[i],inclusive);
	}

	cout<<inclusive<<endl;
} 

int main()
{
	int arr[]={4,1,1,4,2,1};
	int n=sizeof(arr)/sizeof(arr[0]);

	msum_ss_nonadj(arr,n);

	return 0;
}