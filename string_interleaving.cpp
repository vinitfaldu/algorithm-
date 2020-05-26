#include<iostream>
using namespace std;

void s_interleaving(string s1,string s2,string input)
{
	int n=s1.size();
	int m=s2.size();
	bool t[n+1][m+1];
	//cout<<input[0];
	int i,j;
	t[0][0]=true;
	for(i=1;i<n+1;i++)
	{
		if(input[i-1]==s1[i-1])
		{
			t[i][0]=t[i-1][0];
		}
		else
		{
			t[i][0]=false;
		}
	}
	for(j=1;j<m+1;j++)
	{
		if(input[j-1]==s2[j-1])
		{
			t[0][j]=t[0][j-1];
		}
		else
		{
			t[0][j]=false;
		}
	}

	for(i=1;i<n+1;i++)
	{
		for(j=1;j<m+1;j++)
		{
			if(input[i+j-1] == s1[i-1])
			{
				t[i][j]=t[i-1][j];
			} 
			else if(input[i+j-1] == s2[j-1])
			{
				t[i][j]=t[i][j-1];
			}
			else 
			{
				t[i][j]=false;
			}
		}
	}

	if(t[n][m]==true)
	{
		cout<<"String Interleaving...!!"<<endl;
	}
	else
	{
		cout<<"NOT Interleaving"<<endl;
	}

}

int main()
{
	string s1="axy";
	string s2="aab";
	
	string input="aaxaby";

	s_interleaving(s1,s2,input);

	return 0;
}