/*
MONK AND THE ISLAND

Monk visits the land of Islands. There are a total of N islands numbered from 1 to N. Some pairs of islands are connected to each other by Bidirectional bridges running over water.
Monk hates to cross these bridges as they require a lot of efforts. He is standing at Island #1 and wants to reach the Island #N. Find the minimum the number of bridges that he shall have to cross, if he takes the optimal route.

Input:

First line contains T. T testcases follow.
First line of each test case contains two space-separated integers N, M.
Each of the next M lines contains two space-separated integers X and Y , denoting that there is a bridge between Island X and Island Y.

Output:

Print the answer to each test case in a new line.

Constraints:

1 ≤ T ≤ 10
1 ≤ N ≤ 10000
1 ≤ M ≤ 100000
1 ≤ X, Y ≤ N

SAMPLE INPUT

2
3 2
1 2
2 3
4 4
1 2
2 3
3 4
4 2

SAMPLE OUTPUT

2
2
*/

//Use BFS to find Shortest Path and terminate the BFS as soon as nth node as reached

#include<bits/stdc++.h>
using namespace std;


typedef pair<int,int> PII;
void bfs_level(vector <int> adj[],int n,int *level){
    
    queue <int> q;
    
    bool visited[n+1];
    for(int i=1;i<=n;i++) visited[i]=false;
    level[1]=0;
    q.push(1);
    int flag=0;
    visited[1]=true;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        
        for(int j=0;j<adj[node].size();j++)
        {
            if(!visited[adj[node][j]])
            {
            level[adj[node][j]]=level[node]+1;
            
            if(adj[node][j]==n)
            {
                //Prevents further execution
                flag=1;
                break;
            }
            visited[adj[node][j]]=true;
            q.push(adj[node][j]);
            }
        }
        if(flag)
            return;
    }
    
    //delete visited;
    
}

int main()
{
	//code
    int T;
    cin>>T;
    for(int t=0;t<T;t++)
    {
        int N,M;
        cin>>N>>M;
        
        vector <int> adj[N+1];
        int *level=new int[N+1];
        for(int i=1;i<=N;i++)
            level[i]=0;
        
        for(int i=0;i<M;i++)
        {
            int X,Y;
            cin>>X>>Y;
            adj[X].push_back(Y);
            adj[Y].push_back(X);
            
        }
        bfs_level(adj,N,level);
        cout<<level[N]<<endl;
        
        delete level;
        /*
        for(int i=1;i<=N;i++)
            delete edges[i];
        delete edges;
        */
    }
	return 0;
}
