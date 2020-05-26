#include<iostream>
using namespace std;

void egg_dropping(int n,int k)
{
	int i,j,min=0,flag=0;
	int t[k+1][n+1];


	for(i=0;i<k+1;i++)
		t[i][0]=0;	
									// first code in timecomplexity is  O(n^3)...
	for(j=0;j<n+1;j++)					
		t[0][j]=0;					// timeCOMPLEXITY  O(nlogk)......

	for(i=1;i<k+1;i++)
	{
		for(j=1;j<n+1;j++)
		{
			t[i][j]=t[i-1][j-1] + t[i-1][j] + 1;
			if(t[i][j]>=k)
			{
				flag=1;
				min=i;
			}
		}
		if(flag==1)
			break;
	}

	for(i=0;i<min+1;i++)
	{
		for(j=0;j<n+1;j++)
		{
			cout<<t[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"No of Min Eggs : "<<min<<endl;
}

int main()
{
	int n,k;
	cout<<"Enter no of Eggs : ";
	cin>>n;

	cout<<"Enter no of Floors : ";
	cin>>k;

	egg_dropping(n,k);

	return 0;
}