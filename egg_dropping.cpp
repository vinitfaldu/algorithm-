#include<iostream>
using namespace std;

int max(int x,int y)
{
	return x > y ? x : y;
}
int eggDropping(int e,int f)
{
	int i,j,k;
	int a[e][f+1];

	for(i=0;i<e;i++)
		a[i][0]=0;
	for(i=1;i<=f;i++)
		a[0][i]=i;

	for(i=1;i<e;i++)
	{
		for(j=1;j<=f;j++)
		{
			int min=INT_MAX;
			if(i>j)
				a[i][j]=a[i-1][j];
			else
			{
				for(k=j;k>0;k--)
				{
					int val=1+max(a[i][j-k],a[i-1][k-1]);
					//cout<<val<<" ";
					if(val<min)
						min=val;
				}

				a[i][j]=min;
			}	
			//cout<<endl;
		}
	}

	/*for(i=0;i<e;i++)
	{
		for(j=0;j<=f;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}*/

	return a[e-1][f];
}
int main()
{
	int egg=2;
	int floor=36;

	cout<<eggDropping(egg,floor);
	return 0;
}