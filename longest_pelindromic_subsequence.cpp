#include<iostream>
#include<string>
using namespace std;
int max(int x,int y)
{
	return x > y ? x : y;
}
int Lps(string str,int n)
{
	int i,j,k,l;
	int a[n][n];

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			a[i][j]=0;

	for(i=0;i<n;i++)
		a[i][i]=1;

	for(l=2;l<=n;l++)
	{
		for(i=0;i<=n-l;i++)
		{
			j=i+l-1;
			a[i][j]=INT_MIN;
			if(str[i] == str[j])
				a[i][j]=a[i+1][j-1]+2;
			else
			{
				a[i][j]=max(a[i][j-1],a[i+1][j]);
			}
		}
	}

	/*for(i=0;i<n;i++)
	{	
		for(j=0;j<n;j++)
			cout<<a[i][j]<<" ";

		cout<<endl;
	}*/
	i=0;
	j=n-1;
	string s;
	while(s.length() <= ((a[0][n-1])/2))
	{
		if(str[i]==str[j])
		{
			s+=str[i];
			i++;
			j--;
		}
		else if(a[i][j]==a[i+1][j])
		{
			i++;
		}
		else if(a[i][j]==a[i][j-1])
		{
			j--;
		}

		
	}

	
	cout<<s;
	if((a[0][n-1]%2) == 0)
	{
		for(i=s.length()-1;i>=0;i--)
			cout<<s[i];
	}
	else 
	{
		for(i=s.length()-2;i>=0;i--)
			cout<<s[i];
	}
		cout<<endl;

/*	i = 0;
	j = n-1;
	string s;
	do{
		if(str[i]==str[j])
		{
			s += str[i];
			i++;
			j--;
		}
		else if(a[i][j]==a[i+1][j]){
			i++;
		}
		else if(a[i][j]==a[i][j-1]){
			j--;
		}
	}while(s.length()<=a[0][n-1]/2);	
	
	i = s.length()%2 ? s.length()-2 : s.length()-1;
	while(i>=0){
		s += s[i];
		i--;
	}

	cout << s << endl;*/

	return a[0][n-1];
}
int main()
{
	string str="agbdba";  //limitation of same two char. beside not acceptable.
	int n=str.length();

	cout<<Lps(str,n);

	return 0;
}