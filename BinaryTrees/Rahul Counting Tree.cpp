/*
You are given a Binary tree T and an integer K. Input binary Trees T is consisting of N (numbered from 1 to N) nodes rooted at node 1 and each node has a number written on it, where the number written on the ith node is A[i].
Now, Rahul needs to find the number of unordered triplets (i,j,k), such that node i is an ancestor of node j as well as node k, and A[i]+A[j]+A[k]>=K
A node x is considered an ancestor of another node y, if x is parent of y or x is an ancestor of parent of y.
Help Rahul for the same.
Input Format :
Line 1 : 2 space separated integers N and K. 
Line 2 : N space separated integers, where the ith integer denotes A[i].
Line 3 : N-1 space separated integers, where the ith integer represents the parent of node i+1.
Output Format :
Print the required answer on a single line.
Contraints :
1<= N <= 500
0<= A[i] <=10^9
Sample Input 1 :
5 6
1 2 3 4 5
1 2 2 1
Sample Output 1 :
7
Sample Input 2 :
20 63
66 1 20 77 66 71 5 17 12 49 51 14 8 41 54 45 54 77 26 17
1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9 10
Sample Output 2 :
252
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
    
#include <bits/stdc++.h>
#include <iostream>
#define ll long long int
using namespace std;
    

typedef pair<int,int> pi; 


int main() {
    /* Write Your Code Here
    * You have to take input and print the output yourself
    */
    int N,K;
    cin>>N>>K;
    
    ll *A=new ll[N+1];
    ll *parent=new ll[N+1];
    for(int i=1;i<=N;i++){
        cin>>A[i];
    }
    for(int i=2;i<=N;i++){
        cin>>parent[i];
    }
    
    bool ance[N+1][N+1];
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++)
            ance[i][j]=false;
    }
    
    int root=1;
    for(int i=2;i<=N;i++){
        int x=i;
        
        while(x!=root){
            x=parent[x];
            ance[x][i]=true;
        }
    }
    int ans=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            for(int k=1;k<=N;k++){
                if(i!=j && j!=k && i!=k && ance[i][k] && ance[i][j] && (A[i]+A[j]+A[k])>=K)
                    ans++;
            }
        }
    }
    cout<<ans/2<<endl;
    
    
    
    return 0;
}





