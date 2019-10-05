/*
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Prim's algorithm.
For printing MST follow the steps -
1. In one line, print an edge which is part of MST in the format -

v1 v2 w

where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1 <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
Note : Order of different edges doesn't matter.
Input Format :

Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)

Output Format :

MST

Constraints :
2 <= V, E <= 10^5
Sample Input 1 :

4 4
0 1 3
0 3 5
1 2 1
2 3 8
 */

#include <bits/stdc++.h>
using namespace std;
int getMinVertex(bool*visited,int* weight,int V)
{
    int minVertex=-1;
    for(int i=0;i<V;i++)
    {
        if(!visited[i] && ((minVertex==-1)||(weight[minVertex]>weight[i])))
        {
            minVertex=i;
        }
    }
    return minVertex;
}
void prims(int** edges,int V)
{
    int* parent=new int[V];
    int* weight=new int[V];
    bool* visited=new bool[V];
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
        weight[i]=INT_MAX;
    }
    weight[0]=0;
    parent[0]=-1;
    for(int i=0;i<V;i++)
    {
        int mini=getMinVertex(visited,weight,V);
        visited[mini]=true;
        for(int j=0;j<V;j++)
        {
            if(edges[mini][j]!=0)
            {
               if(weight[j]>edges[mini][j] && !visited[j])
               {
                   weight[j]=edges[mini][j];
                   parent[j]=mini;
               }
            }
        }
    }
    for(int i=1;i<V;i++)
    {
        if(parent[i]<i)
        {
            cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
        }
        else
        {
            cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
        }
    }
    delete [] parent;
    delete [] weight;
    delete [] visited;
}
int main()
{
  int V, E;
  cin >> V >> E;
  int** edges=new int*[V];
    for(int i=0;i<V;i++)
    {
        edges[i]=new int[V];
        for(int j=0;j<V;j++)
        {
            edges[i][j]=0;
        }
    }
    for(int i=0;i<E;i++)
    {
        int f,s,w;
        cin>>f>>s>>w;
        edges[f][s]=w;
        edges[s][f]=w;
    }
    prims(edges,V);
  return 0;
}