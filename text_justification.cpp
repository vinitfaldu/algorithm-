#include<iostream>
using namespace std;
void textjusti(string str[],int s,int w)
{
	int i,j,l,q;
	int t[s][s];
	cout << str[0] << endl;
	for(i=0;i<s;i++)
	{
		q=w-(str[i].length());
		t[i][i]=(q*q);
	}

	for(l=2;l<s;l++)
	{
		for(i=0;i<s-l+1;i++)
		{
			j=i+l-1;

			q=w-(str[i].length()+str[j].length()+1);
			if(q>-1)
			{	
				t[i][j]=q*q;
			}
			else
			{
				t[i][j]=-1;
			}	
		}
	}

	for(l=2;l<s;l++)
	{
		for(i=0;i<s-l+1;i++)
		{
			j=i+l-1;
			cout<<t[i][j]<<" ";
		}
		cout<<endl;
	}	
}
int main()
{
	string str[5]={"tushar","roy","likes","to","code"};
	int s=5;
	int width=10;

	textjusti(str,s,width);

	return 0;
}