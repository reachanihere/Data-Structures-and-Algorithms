/*
There exists a special graph which has directed M edges and N nodes and graph contains no cycles. Count the number of ways to reach different nodes from S. A way is called different from others if the destination node or used edges differ. As the ways can be large, print the ways modulo 1000000007.
Include source node as destination also.
Input Format:

Line 1 : Two Integers N and M
Next M lines : Two integers x, y which denotes an edge from x to y
(M+1)st line : S, source

Output Format:

Count of ways

Constraints :
1 <= S, N <= 100005
1 <= M <= 200005
1 <= x , y <= N
Sample Input :

4 3
1 2
2 3
3 4
2

Sample Output :

3

Sample Output Explanation :
From node 2 we can reach - 2, 3 and 4.
 */

#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

long long int dfs(long long int *dp,vector<int> adj[],int source)
{
    dp[source]=(dp[source]%MOD+1)%MOD;
    for(int i=0;i<adj[source].size();i++)
    {
        int node=adj[source][i];
        if(dp[node])
            dp[source]=(dp[source]%MOD+dp[node]%MOD)%MOD;
        else
            dp[source]=(dp[source]%MOD+dfs(dp,adj,node)%MOD)%MOD;
    }
    return dp[source]%MOD;
}

int main() {
	int n, m;
	cin >> n >> m;
    
    vector<int> adj[n+1];
	
    for(int i = 0;i < m; i++) {
		int x, y;
		cin >> x >> y;
        adj[x].push_back(y);
		
	}
    int S;
    cin>>S;
    
    long long int *dp=new long long int[n+1];
    for(int i=1;i<=n;i++)
        dp[i]=0;
    
    dfs(dp,adj,S);
    cout<<dp[S]<<endl;
    
    delete dp;
    

}