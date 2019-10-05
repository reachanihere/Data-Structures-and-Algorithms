/*
We will use the following (standard) definitions from graph theory. Let V be a non-empty and finite set, its elements being called vertices (or nodes). Let E be a subset of the Cartesian product V×V, its elements being called edges. Then G=(V,E) is called a directed graph.

Let n be a positive integer, and let p=(e1,…,en) be a sequence of length n of edges ei∈E such that ei=(vi,vi+1)for a sequence of vertices (v1,…,vn+1). Then p is called a path from vertex v1 to vertex vn+1 in G and we say that vn+1 is reachable from v1, writing (v1→vn+1).

Here are some new definitions. A node v in a graph G=(V,E) is called a sink, if for every node w in G that is reachable from v, v is also reachable from w. The bottom of a graph is the subset of all nodes that are sinks, i.e., bottom(G)={v∈V∣∀w∈V:(v→w)⇒(w→v)}. You have to calculate the bottom of certain graphs.

Input Specification

The input contains several test cases, each of which corresponds to a directed graph G. Each test case starts with an integer number v, denoting the number of vertices of G=(V,E) where the vertices will be identified by the integer numbers in the set V={1,…,v}. You may assume that 1≤v≤5000. That is followed by a non-negative integer e and, thereafter, e pairs of vertex identifiers v1,w1,…,ve,we with the meaning that (vi,wi)∈E. There are no edges other than specified by these pairs. The last test case is followed by a zero.

Output Specification

For each test case output the bottom of the specified graph on a single line. To this end, print the numbers of all nodes that are sinks in sorted order separated by a single space character. If the bottom is empty, print an empty line.

Sample Input

3 3
1 3 2 3 3 1
2 1
1 2
0

Sample Output

1 3
2
 */
#include <bits/stdc++.h>
using namespace std;


typedef unordered_map<int,vector<int> > UM;

void init_vis(bool visited[],int v){
    for(int i=1;i<=v;i++)
        visited[i]=false;
}

void DFSUtil_StackFill(vector<int>adj[],int node,stack<int> &sf,bool* visited){

    visited[node]=true;

    for(int i=0;i<adj[node].size();i++)
    {
        int newnode=adj[node][i];
        if(!visited[newnode])
            DFSUtil_StackFill(adj,newnode,sf,visited);
    }
    sf.push(node);
}

void DFSUtil_reverse(vector<int>adjr[],int node,bool* visited,UM &SCC,int k){
    SCC[k].push_back(node);
    visited[node]=true;

    for(int i=0;i<adjr[node].size();i++)
    {
        int newnode=adjr[node][i];
        if(!visited[newnode])
            DFSUtil_reverse(adjr,newnode,visited,SCC,k);
    }

}


//This funtion will get me SCC of the graph using above two utilities
UM kosarju(vector <int> adj[],vector <int> adjr[],int v,int e){

    //Prepare Stack for finish time and the visited node
    stack<int> sf;
    bool visited[v+1];

    init_vis(visited,v);
    
    //Fill the stack
    for(int i=1;i<=v;i++)
    {
        if(!visited[i])
            DFSUtil_StackFill(adj,i,sf,visited);
    }

    init_vis(visited,v);

    UM SCC;
    int k=0;
    while(!sf.empty())
    {
        int node=sf.top();
        sf.pop();

        if(!visited[node])
        {
            DFSUtil_reverse(adjr,node,visited,SCC,k);
            k++;
        }
    }
    return SCC;

}

//Constructs newvector 'a' by vector b to vector a
void constrV(vector<int> &a,vector<int> &b){
    a.insert(a.end(), b.begin(), b.end());
}

void printV(vector<int> &v){
    sort(v.begin(),v.end());

    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;
}

int main()
{
	//code
    while(true)
    {
        int v,e;
        cin>>v;
        if(v==0)
            break;
        
        cin>>e;
        
        //Prepare two graphs, one orignal and one reverse
        vector <int> adj[v+1];
        vector<int> adj_reversed[v+1];

        for(int i=0;i<e;i++)
        {
            int x,y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj_reversed[y].push_back(x);
        }

        UM SCC=kosarju(adj,adj_reversed,v,e);

        //Prepare SCC mapping
        unordered_map<int,int> sc;
        for(int i=0;SCC[i].size()!=0;i++)
        {
            for(int j=0;j<SCC[i].size();j++)
                sc[SCC[i].at(j)]=i;
        }

        //Check for outgoing edges for all nodes in a SCC
        vector <int> BOTTOM;
        for(int i=0;SCC[i].size()!=0;i++)
        {
            int flag=0;
            for(int j=0;j<SCC[i].size();j++)
            {
                int nd=SCC[i][j];
                for(int k=0;k<adj[nd].size();k++)
                {
                    if(sc[adj[nd][k]]!=i)
                        flag=1;
                }
                if(flag)
                    break;
            }
            if(flag==0)
                constrV(BOTTOM,SCC[i]);
                
        }
        printV(BOTTOM);

        
    }
    
	return 0;
}