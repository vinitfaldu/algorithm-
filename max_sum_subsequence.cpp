#include<iostream>
using namespace std;

void msum_subseq(int arr[],int n)
{
	int i,j,max,mm=INT_MIN,index;
	int max_value[n];
	int seq[n];

	for(i=0;i<n;i++)
	{
		max_value[i]=arr[i];
		seq[i]=i;
	}

	for(i=1;i<n;i++)
	{

		for(j=0;j<i;j++)
		{
			if(arr[j]<arr[i])
			{
				max=max_value[j] + arr[i];
				if(max > max_value[i])
				{
					max_value[i]=max;
					seq[i]=j;
				}

				if(mm < max)
				{	
					mm=max;
					index=i;
				}
			}
		}
	}

	for(i=0;i<n;i++)
	{
		cout<<max_value[i]<<"  ";
	}
	cout<<endl;
	
	for(i=0;i<n;i++)
	{
		cout<<seq[i]<<"  ";
	}
	cout<<endl;

	i=index;
	j=mm;
	cout<<"Reverse Sequence"<<endl;
	while(1)
	{
		cout<<arr[i];
		i=seq[i];
		j=j-max_value[i];

		if(j==0)
			break;
		else
			cout<<"-> ";
	}
	cout<<endl;
}

int main()
{
	int arr[]={4,6,1,3,8,4,6};
	int n=sizeof(arr)/sizeof(arr[0]);

	msum_subseq(arr,n);
}