/*
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
Print the ith vertex number and the distance from source in one line separated by space. Print different vertices in different lines.
Note : Order of vertices in output doesn't matter.
Input Format :

Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)

Output Format :

In different lines, ith vertex number and its distance from source (separated by space)

Constraints :
2 <= V, E <= 10^5
Sample Input 1 :

4 4
0 1 3
0 3 5
1 2 1
2 3 8

Sample Output 1 :

0 0
1 3
2 4
3 5

 */

#include <bits/stdc++.h>
using namespace std;

int findMinDis(int distance[],bool visited[],int n)
{
    int minV=-1;
    for(int i=0;i<n;i++)
    {
        if(!visited[i] && (minV==-1 || distance[minV]>distance[i]))
            minV=i;
    }
    return minV;
}

void dijk(int **edges,int n){
    
    int distance[n];
    bool visited[n];
    for(int i=0;i<n;i++){
        distance[i]=INT_MAX;
        visited[i]=false;
    }
    
    //Starting with node 0
    distance[0]=0;

    
    for(int i=0;i<n-1;i++)
    {
        int minV=findMinDis(distance,visited,n);
        visited[minV]=true;
        
        for(int j=0;j<n;j++)
        {
            if(edges[minV][j] && !visited[j])
            {
                if(distance[j]>distance[minV]+edges[minV][j])
                    distance[j]=distance[minV]+edges[minV][j];
            }
        }
        
    }
    for(int i=0;i<n;i++)
        cout<<i<<" "<<distance[i]<<endl;
}

int main()
{
    int V, E;
    cin >> V >> E;

    int **edges=new int*[V];
    for(int i=0;i<V;i++)
    {
        edges[i]=new int[V];
        for(int j=0;j<V;j++)
            edges[i][j]=0;
    }
    
    for(int i=0;i<E;i++){
        int ei,ej,w;
        cin>>ei>>ej>>w;
        edges[ei][ej]=w;
        edges[ej][ei]=w;
    }
    dijk(edges,V);
    /*
    for(int i=0;i<V;i++){
        delete edges[i];
    }
    delete edges;
*/
  return 0;
}
