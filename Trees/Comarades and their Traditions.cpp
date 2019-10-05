/*
It is the year 2552, the Humans just won a war against a very powerful alien race that had invaded our solar system. The Human army is in celebration mode!
The army has n soldiers. The soldiers are numbers from 1 to n. The army has a superiority hierarchy. Every soldier has one immediate superior. The superior of a superior of a soldier is also a superior to that soldier. So, a soldier may have one or more superiors but only one immediate superior.
Every soldier has to congratulate every other soldier. For a pair of soldiers if one of them is the superior of the other, they will shake hands. Otherwise, they will bump their fists.
You are given the list of immediate superior of all soldiers, your job is to tell how many handshakes and fist bumps will be there. Print the count of handshakes and fist bumps.
NOTE: Among all soldiers, there is one soldier who does not have any superior. He is the commander of the whole army.
Input Format :
Line 1 : Integer t, the number of test cases.
Line 2 : The first line of each test case contains n, the number of soldiers. 
Line 3 : The next line contains n space separated integers. The ith integer represents the immediate superior of the ith soldier.The immediate superior of the commander of the army will be '0'.
Output Format :
Print two space separated integers, the number of handshakes and the number of fist bumps.
Contraints :
1<=t<=10
1<=n<=100000
Sample Input 1:
2
3
0 1 1
2
2 0
Sample Output 1:
2 1
1 0
Sample Input 2 :
5
10
5 5 5 5 0 5 5 5 5 5
10
0 1 1 2 4 5 5 6 7 9 
10
2 3 4 5 6 0 6 7 8 9
15
0 1 1 2 2 3 3 4 4 5 5 6 6 7 7
1
0
Sample Output 2 :
9 36
31 14
25 20
34 71
0 0
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> adj[100001]; 
int heightof[100001]; 
void dfs(int at,int height)
{
    vector<int>::iterator it;
    heightof[at] = height; 
    it = adj[at].begin(); 
    while(it!=adj[at].end())
    { dfs((*it),height+1); 
     it++; 
    } 
    return;
}


int main() {
    /* Write Your Code Here
     * You have to take input and print the output yourself
     */
    //This question can be solved using either Depth First Search or Breadth First Search.
    //First assign height (i.e. distance from the root node) to each node using DFS or BFS. 
    //The height of the ith node is equal to the number of superiors of the ith soldier. So, the number of handshakes for the ith soldier = height of the ith node.
    //Therefore, the number_of_handshakes = sum of heights of all nodes 
    //As number_of_handshakes+number_of_fistbumps=(n*(n-1))/2, we have
    //number_of_fistbumps=(n(n-1))/2 - number_of_handshakes* 
    //dfs has been performed in this case
 
    int t;
    cin>>t;
    while(t--)
    { 
        int n,i,root,par; 
        cin>>n; i = 1; 
 
        while(i<=n) 
        {
            adj[i].clear(); 
            i++; 
        } 
        i = 1;
        while(i<=n) 
        {
            cin>>par; 
            if(par == 0)
            { root = i; 
            } 
            else 
            { 
                adj[par].push_back(i); 
            }
            i++;
 
        } 
        dfs(root,0); 
        i = 1; 
        long long sumofheights = 0,total = (long long)n*(n-1);
        total/=2;
        while(i<=n) 
        {
            sumofheights += (long long)heightof[i]; 
            i++; 
        } 
        cout<<sumofheights<<" "<<total-sumofheights<<endl; 
    }
	return 0;
}

