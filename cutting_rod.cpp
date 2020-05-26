#include<iostream>
using namespace std;

int max(int x,int y)
{
	return x > y ? x : y;
}
int cuttingrod(int len[],int price[],int n,int l)
{
	int i,j;
	int a[n+1][l+1];

	for(i=0;i<=n;i++)
		a[i][0]=0;
	for(i=0;i<=l;i++)
		a[0][i]=0;

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=l;j++)
		{
			if(j>=len[i-1])
			{
				a[i][j]=max(a[i][j-len[i-1]]+price[i-1],a[i-1][j]);
			}
			else
			{
				a[i][j]=a[i-1][j];
			}
		}
	}

	/*for(i=0;i<=n;i++)
	{	
		for(j=0;j<=l;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}*/

	int p=n;
	int q=l;
	
	while(p>0 && q>0)
	{
		if(a[p][q] == a[p-1][q])
		{
			p--;
			//cout<<"@";
		}
		else if(a[p][q] == (a[p][q-len[p-1]]+price[p-1]))
		{
			q=q-len[p-1];
			cout<<len[p-1]<<" ";
			//l=l-len[p-1];
		}
	}	

	cout<<endl;

	return a[n][l];
}
int main()
{
	int len[]={1,2,3,4,5,6,7,8};
	int price[]={1, 5, 8, 9, 10, 17, 17, 20};

	int n=sizeof(len)/sizeof(len[0]);
	int l=8;

	cout<<cuttingrod(len,price,n,l)<<endl;

	return 0;
}