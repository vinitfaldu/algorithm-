#include<iostream>
#include<limits>
#include<vector>		//https://www.tutorialspoint.com/cplusplus-program-to-solve-travelling-salesman-problem-for-unweighted-graph
#include<algorithm>
#include<utility>
using namespace std;

const int MAX=1e4+5;


void travelingSalesman(int graph[][4],int n,int s)
{
	int i,min_cost,path[n-1];
	vector<int > vr;
	for(i=0;i<n;i++)
		if(i!=s)		// start node as a 0...
			vr.push_back(i);

	min_cost=MAX;

	do{
		int curr_cost=0,k=s;		// k=source vertex ...
		for(i=0;i<vr.size();i++)
		{
			curr_cost += graph[k][vr[i]];
			k=vr[i];	
		}
		curr_cost += graph[k][s];			// last path connect to source node...

		//cout<<curr_cost<<endl;
		if(min_cost > curr_cost)
		{
			min_cost=curr_cost; 
			
			for(i=0;i<vr.size();i++)
				path[i]=vr[i];
		}

	}while(next_permutation(vr.begin(),vr.end()));

	cout<<"Min cost :"<<min_cost<<endl;

	cout<<"Path :"<<s<<"->";
	for(i=0;i<vr.size();i++)
		cout<<path[i]<<"->";

	cout<<s<<endl;

}

int main()
{
	int graph[][4]={{0,1,15,6},
 					{2,0,7,3},
 					{9,6,0,12},
 					{10,4,8,0}};
	
	int n=sizeof(graph)/sizeof(graph[0]);

	int source=0;

	travelingSalesman(graph,n,source);

	return 0;
}
/*
input 
{{0,1,15,6},
 {2,0,7,3},
 {9,6,0,12},
 {10,4,8,0}}

output
Min cost :21
Path :0->1->3->2->0

input
{{0,10,15,20}, 
{10,0,35,25}, 
{15,35,0,30 }, 
{20,25,30,0}}

output
min cost :80
Path :________
*/