#include<iostream>
using namespace std;

void sum_query(int matrix[][4],int n,int m,int row1,int col1,int row2,int col2)
{
	int i,j;
	int t[n+1][m+1];

	for(i=0;i<n+1;i++)
	{
		for(j=0;j<m+1;j++)
		{	
			t[i][j]=0;  
		}
	}


	for(i=1;i<n+1;i++)
	{
		for(j=1;j<m+1;j++)
		{
			//cout<<matrix[i-1][j-1]<<t[i][j-1]<<t[i-1][j]<<endl;
			t[i][j] = matrix[i-1][j-1] + t[i][j-1] + t[i-1][j] - t[i-1][j-1];
		}
	}

	for(i=0;i<n+1;i++)
	{
		for(j=0;j<m+1;j++)
		{
			cout<<t[i][j]<<" ";
		}	
		cout<<endl;
	}
	//cout<<endl;
	row1++;
	col1++;
	row2++;
	col2++;

	int ans=t[row2][col2]-t[row1-1][col2]-t[row2][col1-1]+t[row1-1][col1-1];
	cout<<"sum of given 2d array is "<<ans<<endl;


}

int main()
{
	int matrix[][4]={{2,0,-3,4},{6,3,2,-1},{5,4,7,3},{2,-6,8,1}};
	int n=sizeof(matrix)/sizeof(matrix[0]);
	int m=sizeof(matrix[0])/sizeof(matrix[0][0]);

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}

	int row1,col1,row2,col2;
	cout<<"Enter the first Row no: ";
	cin>>row1;
	cout<<"Enter the first Column no: ";
	cin>>col1;
	cout<<"Enter the second Row no: ";
	cin>>row2;
	cout<<"Enter the second Column no: ";
	cin>>col2;

	sum_query(matrix,n,m,row1,col1,row2,col2);

	return 0;
}