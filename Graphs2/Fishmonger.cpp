/*
A fishmonger wants to bring his goods from port to the market. On his route, he has to traverse an area with many tiny city states. Of course he has to pay a toll at each border.
Because he is a good business man, he wants to choose the route in such a way that he has to pay as little money for tolls as possible. On the other hand, he has to be at the market within a certain time, otherwise his fish start to smell.
Given n number of states and the time t in which he has to reach the market. You need to find and print the minimum toll amount that he has to pay in order to reach the market in given time. The first state is the port and last one is the market.
Input Format :

Line 1 : Two integers, n and t
Next n lines : n numbers, specifying for each state the travel time to the i-th state.      
This table is terminated with an empty line. The table of the tolls follows in the same format

Output Format :

Print in one line the total amount of tolls

Constraints :
3 <= n <= 100
1 <= t <= 1000
Sample Input :

4 7
0 5 2 3
5 0 2 3
3 1 0 2
3 3 2 0

0 2 2 7
2 0 1 2
2 2 0 5
7 2 5 0

Sample Output :

6

Sample Case Explanation :
This corresponds to the following situation, the connections are labeled with (time, toll) -

Alt text
The optimal path is Port -> State B -> State A -> Mark
 */


#include<bits/stdc++.h>
using namespace std;

//The trick here is to employ Floyd-Warshall Alogrithm and 0-1 Knapsack

void initialize(int** dp,int n,int t)
{
    for(int i=0;i<n;i++)
    {
        dp[i]=new int[t+1];
        for(int j=0;j<=t;j++)
            dp[i][j]=10000000;
    }

}

void printdparr(int ** a,int n,int t){
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=t;j++)
            cout<<a[i][j]<<" ";
    cout<<endl;
    }
}
int main()
{
	//code
    int n,t;
    cin>>n>>t;

    int **toll=new int*[n];
    int **time=new int*[n];

    
    int **dp=new int*[n];
    initialize(dp,n,t);
    
    //Intiailze for all times.. distance at node 0
    for(int T=0;T<=t;T++)
        dp[0][T]=0;
    
    for(int i=0;i<n;i++)
    {
        time[i]=new int[n];
        for(int j=0;j<n;j++)
            cin>>time[i][j];
    }
    for(int i=0;i<n;i++)
    {
        toll[i]=new int[n];
        for(int j=0;j<n;j++)
            cin>>toll[i][j];
    }
    
    for(int T=0;T<=t;T++)
    {
        for(int town=0;town<n;town++)
        {
            for(int j=0;j<n;j++)
            {
                if(town==j) continue;
                if(time[j][town]>T) continue;
                
                dp[town][T]=min(dp[town][T],toll[j][town]+dp[j][T-time[j][town]]);
            }
        }
    }
    //printdparr(dp,n,t);
    int travel=0;
    for(int T=0;T<=t;T++){
        if(dp[n-1][T]==dp[n-1][t]){
            travel=T;
            break;
        }
    }
    cout<<dp[n-1][t]<<endl;
	return 0;
}
