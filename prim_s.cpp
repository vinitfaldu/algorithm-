#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>

using namespace std;
const int MAX = 1e4 + 5;                // 10000 + 5
typedef pair<long long int, int> PII;
bool marked[MAX];
vector <PII> adj[MAX];

long long int prim(int x)
{
    priority_queue<PII, vector<PII>, greater<PII> > Q;          // min heap
    int y,arr;
    long long minimumCost = 0;
    PII p;
    Q.push(make_pair(0, x));
    while(!Q.empty())
    {
        // Select the edge with minimum weight
        p = Q.top();

        Q.pop();
        x = p.second;
       
        //cout<<x<<endl;
        // Checking for cycle
        if(marked[x] == true)
            continue;
        minimumCost += p.first;
       
        marked[x] = true;
       
        for(int i = 0;i < adj[x].size();++i)
        {
        
            y = adj[x][i].second;

            if(marked[y] == false)
            {    
                Q.push(adj[x][i]);
            }
        }
        
        if(x!=0)
        {
            for(int i=0;i<adj[x].size();i++)
            {
                if(p.first==adj[x][i].first && marked[i]==true)
                {
                 cout<<"Edge bitween "<<adj[x][i].second<<"-"<<x<<" Weight :"<<p.first<<endl;   
                }
            }
        }
        
        
    }
    return minimumCost;
}

int main()
{
    int nodes, edges, x, y;
    long long int weight, minimumCost;
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        adj[x].push_back(make_pair(weight, y));
        adj[y].push_back(make_pair(weight, x));
    }
    // Selecting 1 as the starting node
    minimumCost = prim(0);
    cout<<"Total minimum Cost of Travals :"<<minimumCost<<endl;
    return 0;
}
/*
input
5
7
0
1
12
1
2
11
0
3
25
1
3
8
1
4
12
2
4
17
3
4
15

output

Edge bitween 0-1 Weight :12
Edge bitween 1-3 Weight :8
Edge bitween 1-2 Weight :11
Edge bitween 1-4 Weight :12
Total minimum Cost of Travals :43

*/
/*
input
5
7
0
1
2
1
2
3
0
3
6
1
3
8
1
4
5
2
4
7
3
4
9

output

Edge bitween 0-1 Weight :2
Edge bitween 1-2 Weight :3
Edge bitween 1-4 Weight :5
Edge bitween 0-3 Weight :6
Total minimum Cost of Travals :16
*/