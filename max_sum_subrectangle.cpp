#include<iostream>
#include<string>
using namespace std;
//#define rr 4;
//#define cc 5;

/*int max(int x,int y)
{
	return x > y ? x : y;
}*/
int kodanes(int a[],int *start,int *end,int n)
{
	int max_so_far=0,max_ending_here=0;
	int local_start=0;
	*start = -1;
	*end = -1;

	for(int i=0;i<n;i++)
	{
		max_ending_here=max_ending_here+a[i];
		
		if(max_ending_here<0)
		{
			max_ending_here=0;
			local_start = i+1;
		}

		if(max_so_far < max_ending_here)
		{	
			max_so_far = max_ending_here;
			*start = local_start;
			*end = i;
			
		}

	}
//cout<<*start<<" "<<*end<<" #";
	return max_so_far;
}
void mssr(int arr[][5],int x,int y)
{
	int i,j,k,v,cs,ms,ml,mr,mu,md,start,end;
	int a[x];

	/*for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}*/

	ms=INT_MIN;
	for(i=0;i<y;i++)
	{
		
		for(v=0;v<x;v++)
			a[v]=0;

		for(j=i;j<y;j++)
		{
			for(k=0;k<x;k++)
				a[k]=a[k]+arr[k][j];

			/*for(v=0;v<x;v++)
				cout<<a[v]<<" ";*/

			cs=kodanes(a,&start,&end,x);
			//cout<<endl<<cs<<endl;
			//cout<<start<<" "<<end<<" *"<<endl;
			if(ms<cs)
			{
				ms=cs;
				//cout<<" "<<ms;
				ml=i;
				mr=j;
				mu=start;
				md=end;
			}
		}
	}
//cout<<ml<<mr<<mu<<md;
	for(i=mu;i<=md;i++)
	{
		for(j=ml;j<=mr;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}

	cout<<"Maximum Sum "<<ms<<endl;

}

int main()
{
	//int row=4,column=5;
	int arr[][5]={{2,1,-3,-4,5},{0,6,3,4,1},{2,-2,-1,4,-5},{-3,3,1,0,3}};
	int n=sizeof(arr)/sizeof(arr[0]);
	int m=sizeof(arr[0])/sizeof(arr[0][0]);

	//cout<<n<<m;

	mssr(arr,n,m);    // time complexity is O(n^3) in dynamic programming......

	return 0;
}