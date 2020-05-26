#include<iostream>
using namespace std;

void count_bst(int n)
{
	int t[n+1],i,j;
	t[0]=1;
	t[1]=1;

	for(i=2;i<=n;i++)
	{
		t[i]=0;
		for(j=0;j<i;j++)
		{
			t[i] += t[j]*t[i-j-1];
		}
	}

	

	cout<<"No of BST Generated:"<<t[n]<<endl;
}

int main()
{	
	int n;
	cout<<"HowMany elements :";
	cin>>n;

	count_bst(n);

	return 0;
}