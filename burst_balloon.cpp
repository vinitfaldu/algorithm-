#include<iostream>
using namespace std;

/*int max(int x,int y)
{
	return x > y ? x : y;
}*/

void bb(int arr[],int n)
{
	int i,j,k,l;
	int b[n+2];

	b[0]=1;
	b[n+1]=1;
	for(i=1;i<=n;i++)
		b[i]=arr[i-1];

	int t[n+2][n+2];
	int path[n+2][n+2];

	for(i=0;i<=n+1;i++)
	{
		for(j=0;j<=n+1;j++)
		{
			t[i][j]=0;
			path[i][j]=-1;
		}
	}


	/*for(i=0;i<=n+1;i++)
	{
		for(j=0;j<=n+1;j++)
		{
			cout<<"("<<t[i][j]<<","<<path[i][j]<<")"<<"  ";
		}
	cout<<endl;
	}*/		



	for(l=1;l<=n;l++)
	{
		for(i=1;i<=n-l+1;i++)
		{
			j=i+l-1;
			int max;
			for(k=i;k<=j;k++)
			{
				max=t[i][k-1] + t[k+1][j] + b[i-1]*b[k]*b[j+1];
				//cout<<max<<endl;
		
				if(max > t[i][j])
				{
					t[i][j]=max;
					path[i][j]=k;
				}	

				/*int left=1,right=1;
				if(i!=0)
				{
					left=arr[i-1];
				}
				if(j!=n-1)
				{
					right=arr[j+1];
				}

				int before=0,after=0;
				if(i!=k)
				{
					before=t[i][k-1];
				}
				if(j!=k)
				{
					after=t[k+1][j];
				}

				max=left*arr[k]*right + before + after;
				if(max>t[i][j])
				{
					t[i][j]=max;
					path[i][j]=k;
				}
			*/
			}

		}
	}


	for(i=0;i<=n+1;i++)
	{
		for(j=0;j<=n+1;j++)
		{
			cout<<"("<<t[i][j]<<","<<path[i][j]<<")"<<"  ";
		}
	cout<<endl;
	}	

	i=1;
	j=n;

	while(1)
	{
		l=path[i][j];
		cout<<arr[l-1]<<"-> ";
		if(i==j)
			break;
		else if(l==i)
			i++;
		else if(l==j)
			j--;

	}	
	cout<<endl;
}

int main()
{
	int arr[]={3,1,5,8};
	int n=sizeof(arr)/sizeof(arr[0]);

	bb(arr,n);

	return 0;
}