/*
In DELHI, there are N junctions connected by M bi-directional roads. There is at most one road between any pair of junctions. There is no road connecting a junction to itself. The travel time for a road is the same in both directions.
At every junction there is a single traffic light. Starting from time 0, each light flashes green once every T time units, where the value of T is different for each junction.
A vehicle that is at a junction can start moving along a road only when the light at the current junction flashes green. If a vehicle arrives at a junction between green flashes, it must wait for the next green flash before continuing in any direction. If it arrives at a junction at exactly the same time that the light flashes green, it can immediately proceed along any road originating from that junction.
You are given a city map that shows travel times for all roads. For each junction i, you are given Ti, the time period between green flashes of the light at that junction. The light at junction i flashes green at times 0, Ti, 2Ti, 3Ti, ...
Your task is to find and print the minimum time taken from a given source junction to a given destination junction for a vehicle when the traffic starts. The junctions are identified by integers 1 through N
Input Format :

Line 1 : Two integers N and M. 
Line 2 : N integers - T1, T2,.., TN, describing the time periods at which the traffic lights flash green
Next M lines : Three integers i, j, Lij , where: i and j are the junctions connected by the road and Lij is the time required to move from junction i to junction j using this road.
Line (M+3)rd : Two integers - the source junction and the destination junction.

Assume input of T to be 1-indexed based.
Output Format :

A single line consisting of a single integer, the time taken by a minimum-time path from source to destination.

Constraints
2 ≤ N ≤ 300
2 ≤ M ≤ 14000
1 ≤ Ti ≤ 100
1 ≤ Lij ≤ 100
Sample Input :

4 5
4 3 2 5
1 2 4
1 3 8
2 3 6
2 4 10
3 4 7
1 4

Sample Output :

15

Sample Case Explanation :
1 to 2 to 4 takes time 4 + 2 (wait till 6) + 10 = 16.
1 to 3 to 4 takes time 8 + 0 (no wait) + 7 = 15.
1 to 2 to 3 to 4 takes time 4 + 2 (wait till 6) + 6 + 0 (no wait) + 7 = 19.
1 to 3 to 2 to 4 takes time 8 + 0 (no wait) + 6 + 1 (wait till 15) + 10 = 25.
 */

#include <iostream>
#include <limits.h>
using namespace std;

int findMin(int *time ,bool* visited,int n)
{
    int minV=-1;
    
    for(int i=1;i<=n;i++)
    {
        if(!visited[i] && (minV==-1 || time[minV]>time[i]))
            minV=i;
    }
    return minV;
}


void printarr(int *a,int n){
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

void dijkt(int **edges,int n,int* period, int* time,int src,int dest){
    
    bool *visited=new bool[n+1];
    for(int i=1;i<=n;i++)visited[i]=false;
    
    time[src]=0;
    for(int i=1;i<=n;i++)
    {
        int minV=findMin(time,visited,n);
        visited[minV]=true;
        
        for(int j=1;j<=n;j++)
        {
            if(edges[minV][j] && !visited[j])
            {
                if(j!=dest)
                {
                    int t_pass=time[minV]+edges[minV][j];
                    int waitime;
                    if(t_pass%period[j]==0)
                        waitime=0;
                    else
                        waitime=period[j]-t_pass%period[j];
                    int t=t_pass+waitime;
                
                    if(t<time[j])
                        time[j]=t;
                }
                else
                {
                    int t=time[minV]+edges[minV][j];
                    if(t<time[j])
                        time[j]=t;
                }
            }
        }
    }
    delete visited;
    
    
}

int main() {
	int n, m;
	cin >> n >> m;
    
    int **edges=new int*[n+1];
    for(int i=1;i<=n;i++)
    {
        edges[i]=new int[n+1];
        for(int j=1;j<=n;j++)
            edges[i][j]=0;
    }
    
    int* period=new int[n+1];
    int* time=new int[n+1];
    for(int i=1;i<=n;i++)
    {
        time[i]=INT_MAX;
        cin>>period[i];
    }
    time[0]=INT_MAX;
    for(int i=0;i<m;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        edges[x][y]=w;
        edges[y][x]=w;
    }
    int src,dest;
    cin>>src>>dest;
    
    dijkt(edges,n,period,time,src,dest);
    
    int ans=time[dest];
    cout<<ans<<endl;
    
    //printarr(time,n);
    delete period;
    delete time;
    for(int i=1;i<=n;i++) delete edges[i];
    delete edges;

}