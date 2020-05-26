#include<iostream>
#include<string>
using namespace std;

int min(int x,int y,int z)
{
	int t = (x < y) ? x : y;
	return (t < z) ? t : z;
}
int editdistance(string str1,string str2,int m,int n)
{
	int i,j;
	int dp[m+1][n+1];

	for(i=0;i<=m;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(i==0)
				dp[i][j]=j;
			else if(j==0)
				dp[i][j]=i;
			else if(str1[i-1]==str2[j-1])
				dp[i][j]=dp[i-1][j-1];
			else 
			{
				dp[i][j]=min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]) + 1;
			}
		}
	}


	for(i=0;i<=m;i++)
	{
		for(j=0;j<=n;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}	

	i=m;
	j=n;

	while(i>0 && j>0)
	{
		if(str1[i-1]==str2[j-1])
		{
			i--;
			j--;
		}
		else if(dp[i][j]==dp[i-1][j-1]+1)
		{
			cout<<"Edit "<<str2[j-1]<<" in string2 to "<<str1[i-1]<<" in string1"<<endl;
			i--;
			j--;
		}
		else if(dp[i][j]==dp[i-1][j]+1)
		{
			cout<<"Delete "<<str1[i-1]<<" in string1 " <<endl;
			i--;
		}
		else if(dp[i][j]==dp[i][j-1]+1)
		{
			cout<<"Delete "<<str2[j-1]<<" in string2"<<endl;
			j--;
		}
		else 
		{
			cout<<"some wrong in string"<<endl;
			break;
		}
	}	

	return dp[m][n];	
}

int main()
{
	string str1="abcdef";
	string str2="azced";
	int m=str1.length();
	int n=str2.length();

	cout<<editdistance(str1,str2,m,n);

	return 0;
}