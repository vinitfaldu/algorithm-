#include<iostream>
using namespace std;

int pelindrome(string s,int i,int j)
{
	int n=i,m=j;
	while(n<m)
	{
		if(s[n++] != s[m--])
		{
			return 0;
		}
	}
	return 1;
}

void split(string s)
{
	int i,j,k,l,n;
	n=s.size();
	int t[n][n];

	for(i=0;i<n;i++)
		t[i][i]=0;

	for(l=2;l<=n;l++)
	{
		
		for(i=0;i<n-l+1;i++)
		{
			j=i+l-1;
			t[i][j]=INT_MAX;

			if(pelindrome(s,i,j))
			{
				t[i][j]=0;
			}
			else
			{
				for(k=i;k<j;k++)
				{
					int a=1+t[i][k]+t[k+1][j];
					if(t[i][j]>a)
						t[i][j]=a;
				}
			}	
		}
	}

	/*for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<t[i][j]<<" ";
		}
		cout<<endl;
	}*/

	cout<<"no of split is "<<t[0][n-1]<<endl;
	cout<<"Totale partition "<<t[0][n-1]+1<<endl;
}
int main()
{
	string str="ababbbabbababa";

	split(str);

	return 0;
}