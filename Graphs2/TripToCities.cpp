/*
You want to plan a trip to a country with N cities and M bidirectional roads. But there is a special city called capital C, where you will land. But there is a restriction, you can only visit cities which are at most k distance from the capital. Can you count the number of cities that you can visit during your trip (including capital) ?
Input Format :

Line 1 : Four Integers N , M ,C (Capital), K
Next M lines : Three integers X, Y, Z where city X and Y have a road between them which has length Z

Output Format :

Print the number of cities that you can visit during your trip

Constraints :
1 <= N <= 100005
1 <= M <= 200005
1 <= X,Y <=N
1 <= Z <= 100
Sample Input :

4 3 1 1
1 2 1
2 3 1
3 4 1

Sample Output :

2
 */

#include <iostream>
#include <limits.h>
#include <vector>
#include <queue>
using namespace std;
/*
int findMin(int* dist,bool* visited,int n)
{
    int minV=-1;
    for(int i=1;i<=n;i++)
    {
        if(!visited[i] && (minV==-1 || dist[minV]>dist[i]))
            minV=i;
    }
    return minV;
}
*/
typedef pair<int,int> PII;
void dijk(vector<pair<int,int> > adj[],int n,int C,int *dist){
    
    
    dist[C]=0;
    priority_queue<PII,vector<PII>,greater<PII> >Q;
    bool *visited=new bool[n+1];
    for(int i=1;i<=n;i++) visited[i]=false;
    
    Q.push(make_pair(0,C));
    while(!Q.empty())
    {
        pair<int,int>p=Q.top();
        Q.pop();
        int minV=p.second;
        
        if(visited[minV])
            continue;
        visited[minV]=true;
        
        for(int j=0;j<adj[minV].size();j++)
        {
            int ncity=adj[minV][j].second;
            int road=adj[minV][j].first;
        
            if(dist[ncity]>dist[minV]+road)
            {
                dist[ncity]=dist[minV]+road;
                Q.push(make_pair(dist[ncity],ncity));
            }
        }
    }
}


int main() {
	int n, m, c, k;
	cin >> n >> m >> c >> k;
	
    vector <pair <int,int> > adj[n+1];
    
    for(int i = 0;i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
        adj[x].push_back(make_pair(z,y));
        adj[y].push_back(make_pair(z,x));
		
	}
    int *dist=new int[n+1];
    for(int i=0;i<=n;i++)
        dist[i]=INT_MAX;
    
    dijk(adj,n,c,dist);
    
    int count=0;
    for(int i=1;i<=n;i++)
        if(dist[i]<=k) count++;
    
    cout<<count<<endl;
    
    
}