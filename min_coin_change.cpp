#include<iostream> 
  
using namespace std; 


int count( int S[], int m, int n ) 
{ 
	
	int i,j;
	int a[n+1],b[n+1]; 
	
	//memset(a,99999,sizeof(a));
	for(j=0;j<=n;j++) 
		a[j]=999;

	a[0]=0;
	//memeset(b,-1,sizeof(b));
	for(j=0;j<=n;j++) 
		b[j]=-1; 

	for(i=0;i<m;i++) 
	{ 
			
		for(j=1;j<=n;j++) 
		{ 
			if(j>=S[i])
			{	
				if(a[j] > 1+a[j-S[i]])
				{
					a[j]=1+a[j-S[i]];
					b[j]=i;
				}
			}
		} 
	} 

/*for(j=0;j<=n;j++) 
	cout<<a[j]<<" "; 

cout<<endl;
for(j=0;j<=n;j++) 
	cout<<b[j]<<" "; */

	

	if(b[n] == -1)
	{
		cout<<"No solution possible"<<endl;
		return 0;
	}

	int start=n;
	while(start != 0)
	{
		int v=b[start];
		cout<<S[v]<<" ";
		start = start - S[v];
	}

	cout<<endl;

	return a[n]; 
} 
 

  
// Driver Code 
int main() 
{ 
    int arr[] = {2,5,6}; 
    int m = sizeof(arr)/sizeof(arr[0]); 
    int n = 4; 
    cout<<count(arr, m, n); 
    return 0; 
} 


/*##################################################
int i,j,count;

    for(i=0;i<arr_count;i++)
    {
        count=0;
        *(result_count+i)=0;
        for(j=0;j<arr_count;j++)
        {
            if(i == *(arr+j))
            {
                count++;
                *(result_count+i)=count;
            }
        }
    }

    return result_count;


################

 while(1)
   {
       if(*(rating+i) < *(rating+j) && *(rating+j) <*(rating+k))
       {
           count++;
       }
       else
           k++;
       
       if(k==ratingSize || *(rating+j) > *(rating+k))
        {   
            j++;
            k=j+1;
        }
       if(j==ratingSize-1 || *(rating+i) > *(rating+j))
       {
           i++;
           j=i+1;
       }
       if(i==ratingSize-2)
           break;
   }*/