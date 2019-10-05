/*
Nathan Reynolds is a famous smuggler and captain of a spaceship "Serenade".He was offered a potentially dangerous job on Ariel, one of the border planets of the 
star system. But to save all the "honest" earnings of the previous adventures, he decided to store them on one of the planets on the way to the border.

Star system is represented by  n planets and m space tunnels between them. Space tunnel is one-way wormhole to travel from one planet to another, requiring an amount of gravitonium to perform the gravity jump. There may be several space tunnels between two planets, but no space tunnel leads to the same planet it starts from.

Your task as a first officer is to find the minimum amount of gravitonium to travel from the base planet to Ariel, visiting some other planet to store the earnings, and return back to base, picking up the earnings on the way back.

Note, that storing the earnings in a base planet or the planet, where the job is taking place, is not allowed. But it's allowed to visit Ariel with the earnings as long as you are not doing a job on this planet.

Input format

The first line of input contains four integers n,  m,  s and  t — number of planets in a star system, number of space tunnels, the index number of the base planet and the index number of Ariel, respectively.

Each of the next m lines contains three integers  u,  v and g — the planet, where the space tunnel starts, the planet, where the space tunnel goes to, and the amount of gravitonium required to travel through the space tunnel, respectively ().

Constraints

2≤n≤10^5
1<=m<=10^5
1≤s,t≤n
s≠t 
1≤u,v≤n 
1≤g≤103

Output format

 Output the minimum time required to travel from the base planet to Ariel, visiting some other planet to store the earnings, and return back to base, picking up the earnings on the way back, or output -1, if it's impossible.

Sample input

5 9 1 2
1 3 1
1 5 5
2 5 1
3 1 10
3 4 5
4 2 1
5 1 5
5 3 100
5 4 5

Sample output

17
*/

#include<bits/stdc++.h>
using namespace std;


void dijkistra(long long s , vector<pair<long long , long long>>* vec , long long* dist , long long n){

    set<pair<long long,long long>> ourset;

    dist[s] = 0;

    for(long long i=1 ; i<=n ; i++){
        ourset.insert({dist[i],i});
    }

    while(ourset.size()){
        set<pair<long long , long long>> :: iterator it;
        it = ourset.begin();
        pair<long long , long long> p = *it;
        ourset.erase(it);
        long long min_ver = p.second;
        // cout<<min_ver<<endl;
        for(long long i=0 ; i<vec[min_ver].size() ; i++){
            long long l = vec[min_ver][i].first;
            long long cost = dist[min_ver] + vec[min_ver][i].second;
            if(dist[l] > cost){
                ourset.erase(make_pair(dist[l] , l));
                dist[l] = cost; 
                ourset.insert(make_pair(dist[l] , l));
            }
        }
    }



}



int main()
{
    //code

    long long n,m,s,t;
    cin>>n>>m>>s>>t;

    vector<pair<long long , long long>> graph[n+1];
    vector<pair<long long , long long>> transpose[n+1]; //This transpose is prepared for fast calculation of distances from destination node

    for(long long i=0 ; i<m ; i++){
        long long s,d,w;
        cin>>s>>d>>w;
        graph[s].push_back({d,w});
        transpose[d].push_back({s,w});
    }

    long long * dist1 = new long long[n+1];//This one for dist[source][i]
    long long* dist2 = new long long[n+1];//dist[i][dest]
    long long* dist3 = new long long[n+1];//dist[dest][i]
    long long* dist4 = new long long[n+1];//dist[i][source]

    for(long long i=0 ; i<=n ; i++){
        dist1[i] = INT_MAX;
        dist2[i] = INT_MAX;
        dist3[i] = INT_MAX;
        dist4[i] = INT_MAX;
    }

    dijkistra(s , graph , dist1 , n);
    dijkistra(t , transpose , dist2 , n);
    dijkistra(t , graph , dist3 , n);
    dijkistra(s , transpose , dist4 , n);

    long long min_path = INT_MAX;


    for(long long i=1 ; i<=n ; i++){
        if(i==s || i==t){
            continue;
        }
        min_path = min(dist1[i] + dist2[i] + dist3[i] + dist4[i] , min_path);
    }

    
    if(min_path == INT_MAX){
        cout<<-1<<endl;
        return 0;
    }
    
    cout<<min_path<<endl;


    return 0;
}


