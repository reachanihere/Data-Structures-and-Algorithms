#include <bits/stdc++.h>
using namespace std;


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

void DFSUtil_reverse(vector<int>adjr[],int node,bool* visited,unordered_map<int,vector<int> > &SCC,int k){
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
unordered_map<int,vector<int> > kosarju(vector <int> adj[],vector <int> adjr[],int v,int e){

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

    unordered_map<int,vector<int> > SCC;
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

int main(){
    int v,e;
    cin>>v>>e;

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

    unordered_map<int,vector<int> > SCC=kosarju(adj,adj_reversed,v,e);

    //Print SCC
    for(int i=0;SCC[i].size()!=0;i++)
    {
        cout<<"Connect component "<<i<<": ";
        for(int j=0;j<SCC[i].size();j++)
            cout<<SCC[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}