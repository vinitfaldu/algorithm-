#include<iostream>
using namespace std;

void binary_number(int n)
{
	int i,ans[n];

		ans[0]=2;
		ans[1]=3;
	
	for(i=2;i<n;i++)
		ans[i]=ans[i-1]+ans[i-2];

	cout<<"Numbers without consecutive 1's in binary representation is: "<<ans[n-1]<<endl;

}

int main()
{
	int n;
	cout<<"Howmany Bits :";
	cin>>n;

	binary_number(n);

	return 0;
}