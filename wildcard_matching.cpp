#include<iostream>
using namespace std;
void wildcard_match(string pattern,string str)
{
	int i,j;
	int m=pattern.size();
	int n=str.size();
	

	int index=0;
	bool isFirst=true;
	for(i=0;i<m;i++)
	{
		if(pattern[i]=='*')
		{
			if(isFirst)
			{
				pattern[index++]=pattern[i];
				isFirst=false;
			}
		}
		else
		{								//handel it this problem, every time different metrix generated....
			pattern[index++]=pattern[i];
			isFirst=true;
		}
	}

	//cout<<pattern<<endl;
	bool t[n+1][index+1];

//cout<<m<<n<<" $";
	
	/*for(i=1;i<n+1;i++)
		t[0][i]=false;

	for(i=1;i<m+1;i++)
		t[i][0]=false;*/

	for(i=0;i<n+1;i++)
	{
		for(j=0;j<index+1;j++)
		{
			t[i][j]=false;
		}
	}

	t[0][0]=true;
	if(index>0 && pattern[0]=='*')
	{
		//cout<<"@";
		t[0][1]=true;
	}	
/*
	for(i=1;i<m+1;j++)
		if(pattern[j-1]=='*')
			t[0][j]=t[0][j-1];*/

	/*for(i=0;i<n+1;i++)
	{
		for(j=0;j<m+1;j++)
		{
			cout<<t[i][j]<<" ";
		}
		cout<<endl;
	}*/

	//cout<<"@@@@@@"<<endl;

	for(i=1;i<n+1;i++)
	{
		for(j=1;j<index+1;j++)
		{
			/*if(str[i-1] == pattern[j-1])
			{
				t[i][j]=true;
			}
			else */if(pattern[j-1] == '?' || str[i-1]==pattern[j-1])
			{
				//cout<<" #"<<j<<"# ";
				t[i][j]=t[i-1][j-1];
			}
			else if(pattern[j-1] == '*')
			{
				//cout<<" #"<<j<<"# ";
				t[i][j]=(t[i-1][j] || t[i][j-1]);
			}
			/*else
			{
				t[i][j]=false;
			}*/	
		}
	}

	for(i=0;i<n+1;i++)
	{
		for(j=0;j<index+1;j++)
		{
			cout<<t[i][j]<<" ";
		}
		cout<<endl;
	}

	if(t[n][index]==true)
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}

}
int main()
{
	string patt="***ba****ab";
	string str="baaab";

	wildcard_match(patt,str);

	return 0;
}