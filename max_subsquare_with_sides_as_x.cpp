#include<iostream>
using namespace std;
int min(int x,int y)
{
	return x < y ? x : y;
}
void max_subsquare(int arr[][5],int n,int m)
{
	int i,j,ans=INT_MIN,t;
	int vertical[n+1][m+1],horizontal[n+1][m+1];

	for(i=0;i<n+1;i++)
	{
		for(j=0;j<m+1;j++)
		{
			vertical[i][j] = 0;
			horizontal[i][j] = 0;
		}
	}

	for(i=1;i<n+1;i++)
	{
		for(j=1;j<m+1;j++)
		{
			if(arr[i-1][j-1]=='O')
			{
				vertical[i][j] = 0;
				horizontal[i][j] = 0;
			}
			else
			{
				vertical[i][j] = vertical[i-1][j] + 1;
				horizontal[i][j] = horizontal[i][j-1] + 1;
			}
		}
	}

	/*for(i=0;i<n+1;i++)
	{
		for(j=0;j<m+1;j++)
		{
			cout<<"("<<vertical[i][j]<<","<<horizontal[i][j]<<")"<<" ";
		}
		cout<<endl;
	}*/

	for(i=n;i>=0;i--)
	{
		for(j=m;j>=0;j--)
		{
			int minimum=min(vertical[i][j],horizontal[i][j]);
			//cout<<minimum<<" @";
			if(minimum>ans)
			{	
				for(t=minimum;t>0;t--)
				{	
					int verti=vertical[i][j-t+1];
					int hori=horizontal[i-t+1][j];
					

					if(verti >= t && hori >= t)
					{
						//cout<<i<<","<<j<<" "<<t<<") "<<endl;
						//cout<<verti<<","<<hori<<endl;
						if(t>ans)
						{
							ans=t;
							break;
						}	
					}
				}
			}
		}
	}

	cout<<"minimum Sub Square sides as X size is :"<<ans<<endl;
}
int main()
{
	int arr[][5]={{'O', 'O', 'O', 'O', 'X'},
                  {'X', 'O', 'X', 'X', 'X'},
                  {'X', 'O', 'X', 'O', 'X'},
                  {'X', 'X', 'X', 'X', 'X'},
                  {'O', 'O', 'X', 'X', 'X'}};

	int n=sizeof(arr)/sizeof(arr[0]);
	int m=sizeof(arr[0])/sizeof(arr[0][0]);

	max_subsquare(arr,n,m);			  

	return 0;
}