#include<iostream>
using namespace std;

void swap(int *p,int *q)
{
	int temp=*p;
	*p=*q;
	*q=temp;
} 

void box_stacking(int box[][3],int n)
{
	int i,j,size;
	size=3*n;
	int t[size][3];

	//insert in 2D array....
	for(i=0;i<size;i++)
	{
		if(box[i/3][(i+1)%3] > box[i/3][(i+2)%3])
		{	
			t[i][0]=box[i/3][(i+1)%3];  	//length(>width)
			t[i][1]=box[i/3][(i+2)%3]; 		//width
		} 
		else
		{
			t[i][0]=box[i/3][(i+2)%3];  	//length(>width)
			t[i][1]=box[i/3][(i+1)%3];  	//width
		}
		t[i][2]=box[i/3][(i+3)%3];  		//height
	}
	/*for(i=0;i<3*n;i++)
	{
		for(j=0;j<3;j++)
		{
			cout<<t[i][j]<<" ";
		}
		cout<<endl;
	}*/

	//Sort all posibility....
	for(i=0;i<size;i++)
	{
		for(j=0; j<(size-i)-1; j++)
		{
			if(t[j][0]*t[j][1] < t[j+1][0]*t[j+1][1])
			{
				swap(t[j][0],t[j+1][0]);
				swap(t[j][1],t[j+1][1]);
				swap(t[j][2],t[j+1][2]); 
			}
		}
	}
	/*for(i=0;i<3*n;i++)
	{
		for(j=0;j<3;j++)
		{
			cout<<t[i][j]<<" ";
		}
		cout<<endl;
	}*/

	//cout<<"#########"<<endl;
	int max[size],result[size];

	for(i=0;i<size;i++)
	{
		max[i]=t[i][2];
		result[i]=i;
	}

	/*for(i=0;i<size;i++)
	{
		cout<<max[i]<<" "<<result[i]<<endl;
	}*/
//cout<<"#########"<<endl;
	for(i=1;i<size;i++)
	{
		int m=INT_MIN;
		for(j=0;j<i;j++)
		{
			if(t[j][0]>t[i][0] && t[j][1]>t[i][1])
			{
				m=max[j]+t[i][2];
				if(max[i] < m)
				{
					max[i]=m;
					result[i]=j;
				}
			}
		}
	}

	for(i=0;i<size;i++)
	{
		cout<<max[i]<<" "<<result[i]<<endl;
	}

	j=size-1;
	int flage=0;
	while(1)
	{
		for(i=0;i<3;i++)
		cout<<t[j][i]<<" ";

		cout<<endl;
		j=result[j];

		if(j==0 && flage==0)
		{	flage=1; }
		else if(flage == 1)
		{	break; }
	}

}

int main()
{
	int box[][3]={{1,2,4},{3,2,5}};
	int n=sizeof(box)/sizeof(box[0]);

	box_stacking(box,n);

	return 0;
}