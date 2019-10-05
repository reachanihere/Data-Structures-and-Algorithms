/*
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
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

class Edge{
    public:
    int weight;
    int first;
    int second;
    
    Edge(){
        weight=0;
        first=0;
        second=0;
    }
    
    Edge(int w,int f,int s){
        weight=w;
        first=f;
        second=s;        
    }
    bool operator <(const Edge &e1) const{
        return weight>=e1.weight;
    }
};

int main()
{
    int V, E;
    cin >> V >> E;
    
    priority_queue<Edge> pq;
    
    vector <Edge> MST;
    
    for(int i=0;i<E;i++){
        int ei,ej,wi;
        cin>>ei>>ej>>wi;
        
        Edge E(wi,ei,ej);
        pq.push(E);
    }
    
    int count=0;
    int *parent=new int[V];
    
    for(int i=0;i<V;i++)
        parent[i]=i;
    
    while(count<V-1 && !pq.empty()){
        Edge e=pq.top();
        pq.pop();
        
        int x1=parent[e.first];
        
        while(x1!=parent[x1])
            x1=parent[x1];
        
        int x2=parent[e.second];
        while(x2!=parent[x2])
            x2=parent[x2];
        
        if(x1!=x2){
            count++;
            MST.push_back(e);
            
            parent[x1]=x2;
        }
    }
    
    for(int i=0;i<MST.size();i++){
        
        int a=(MST[i].first<=MST[i].second)?MST[i].first:MST[i].second;
        int b=(MST[i].first>MST[i].second)?MST[i].first:MST[i].second;
        
        cout<<a<<" "<<b<<" "<<MST[i].weight<<endl;;
    }

  return 0;
}
