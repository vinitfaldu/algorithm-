#include<iostream>
using namespace std;

int max(int x,int y)
{
	return x > y ? x : y;
}
int bss(int price[],int n,int k)
{
	int i,j,maxDiff;
	int a[k+1][n];

	for(i=0;i<n;i++)
		a[0][i]=0;

	for(i=0;i<=k;i++)
		a[i][0]=0;


	for(i=1;i<=k;i++)
	{
		maxDiff =-price[0];	
		for(j=1;j<n;j++)
		{
			a[i][j]=max(a[i][j-1],maxDiff+price[j]);
			maxDiff=max(maxDiff,a[i-1][j]-price[j]);
		}
	}

	/*for(i=0;i<=k;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}*/
	int l=n;
	int profit=a[k][n-1];
	int rem=a[k][n-1];
	i=k; j=n-1;
	while(i>0 && j>0)
	{
		if(a[i][j-1]==rem)
		{
			j--;
			//l--;
		}
		else
		{
			cout<<"Sell of Day :"<<j<<"  "<<price[j]<<endl;
			profit=a[i][j]-price[j];
			i--;
			while(1)
			{
				if(profit==a[i][j]-price[j])
				{
					rem=a[i][j];
					cout<<"Buy of Day  :"<<j<<" -"<<price[j]<<endl;
					break;
				}
				j--;
			}
		}

	}
	cout<<"Maximum Profit =";
	return a[k][n-1];
}
int main()
{
	int k=3;
	int price[]={2,5,7,1,4,3,1,3};
	int n=sizeof(price)/sizeof(price[0]);

	cout<<bss(price,n,k)<<endl;

	return 0;
}