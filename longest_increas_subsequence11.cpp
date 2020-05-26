// binary search....    O(nlogn)
#include<iostream>
using namespace std;
int ceilIndex(int arr[],int t[],int len,int q)
{
	int start=0;
	int end=len;

	while(start<=end)
	{
		if(arr[t[start]]<q)
		{ 
			start++;
		}
		else if(arr[t[start]]>q)
			return start;
	}

	return -1;
}
	
//	.........second method to travels in t[]..........

/*	while(start<=end)
	{
		middum=(start+end)/2;
		if(middum<len && arr[t[middum]]<q && q<=arr[t[middum+1]])
		{ 
			return middum+1;
		}
		else if(arr[t[middum]]<q)
		{
			start=middum+1;
		}
		else
		{
			end=middum-1;
		}
	}*/
void liss(int arr[],int n)
{
	int i,j,len;
	int r[n],t[n];

	for(i=0;i<n;i++)
		r[i]=-1;

	/*for(i=0;i<n;i++)
		t[i]=INT_MAX;*/

	t[0]=0;
	len=0;
	for(i=1;i<n;i++)
	{
		if(t[0]>arr[i])
		{
			t[0]=i;
		}
		else if(arr[t[len]]<arr[i])
		{
			len++;
			t[len]=i;
			r[t[len]]=t[len-1];
		}
		else
		{
			//cout<<" #";
			int index=ceilIndex(arr,t,len,arr[i]);
			t[index]=i;
			r[t[index]]=t[index-1];
		}
	}

	/*for(i=0;i<n;i++)
		cout<<t[i]<<" ";
	cout<<endl;

	for(i=0;i<n;i++)
		cout<<r[i]<<" ";

	cout<<endl;*/

	i=n-1;
	cout<<"reverse print the subsequence:"<<endl;
	while(1)
	{
		if(i == -1)
			break;

		cout<<arr[i]<<" ";
		i=r[i];
	}

	cout<<endl<<"Size of longest subsequence: "<<(len+1)<<endl;

} 
int main()
{
	int arr[]={3,4,-1,5,8,2,3,12,7,9,10};
	int n=sizeof(arr)/sizeof(arr[0]);

	//cout<<"@";
	liss(arr,n);

	return 0;
}