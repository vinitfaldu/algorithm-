#include<iostream>
using namespace std;

int max(int x,int y)
{
	return x > y ? x : y;
}

int mjre(int arr[],int n)
{

}

int main()
{
	int arr[]={2,3,1,1,2,4,2,0,1,1};
	int n=sizeof(arr)/sizeof(arr[0]);

	cout<<mjre(arr,n)<<endl;

	return 0;
}