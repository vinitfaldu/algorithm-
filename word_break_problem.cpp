#include<iostream>
using namespace std;
int dd(string s)
{
	string dict[]={"I","am","ace","a"};
	int m=sizeof(dict)/sizeof(dict[0]);

	for(int i=0;i<m;i++)
		if(s == dict[i])
			return 1;

	return 0;		
}
void wbp(string str,int n)
{
	int i,j,k,l;
	int a[n][n];
	int store[n][n];

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			a[i][j]=0;

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			store[i][j]=-1;	

	/*for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout<<a[i][j]<<" ";
	
		cout<<endl;
	}*/


	for(i=0;i<n;i++)
	{
		string st="";
		st+=str[i];
		a[i][i]=dd(st);
	}

	/*for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout<<a[i][j]<<" ";
	
		cout<<endl;
	}*/

	for(l=2;l<=n;l++)
	{
		for(i=0;i<n-l+1;i++)
		{
			j=i+l-1;

			//a[i][j]=0;

			string s="";
			for(k=i;k<j;k++)
			{
				s+=str[k];
				if(a[i][k]==1 && a[k+1][j]==1)
				{	
					a[i][j]=1;
					store[i][j]=k;
					break;
				}	
			}

			//cout<<i<<j;
			s+=str[j];
			//cout<<s<<endl;
			if(dd(s))
			{	
				a[i][j]=dd(s);
				store[i][j]=j;
			}
		}
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout<<store[i][j]<<"   ";
	
		cout<<endl;
	}
cout<<endl<<"!!!!!!!!!!!!!"<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout<<a[i][j]<<" ";
	
		cout<<endl;
	}
	j=0;
	int count=n;
	while(count>0)
	{
		int i=store[n-count][n-1];
		while(j<=i)
		{
			cout<<str[j];
			j++;
			count--;
		}
			
		cout<<" ";
	}

	cout<<endl;
	if(a[0][n-1] == 1)
	{
		cout<<"True"<<endl;
	}
	else
		cout<<"False"<<endl;

}
int main()
{
	string s="Iamace";
	int n=s.length();
//cout<<n<<endl;
	wbp(s,n);

	return 0;
}
