/*
You are given with an array of integers and an integer K. Write a program to find and print all pairs which have difference K.
Best solution takes O(n) time. And take difference as absolute.
Input Format :

Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)
Line 3 : K

Output format :

Print pairs in different lines (pair elements separated by space). In a pair, smaller element should be printed first.
(Order of different pairs is not important)

Constraints :
1 <= n <= 5000
Sample Input 1 :

4 
5 1 2 4
3

Sample Output 1 :

2 5
1 4

Sample Input 2 :

4
4 4 4 4 
0

Sample Output 2 :

4 4
4 4
4 4
4 4
4 4
4 4
*/
#include <bits/stdc++.h>
using namespace std;

void printPairs(int *input, int n, int k) {
	// Write your code here
    
    unordered_map<int,int>m;
    
    //Unusual case of zero
    if(k==0){
        for(int i=0;i<n;i++){
            
            if(m.count(input[i]))
                m[input[i]]+=1;
            else
                m[input[i]]=0;
            
            if(m[input[i]]){
                int t=m[input[i]];
                for(int j=1;j<=t;j++)
                    cout<<(input[i])<<" "<<(input[i])<<endl;
            }
        }
    }
    else{
        for(int i=0;i<n;i++){
        
            if(m.count(input[i]))
                m[input[i]]+=1;
            else
                m[input[i]]=1;
        
            if(m.count(input[i]+k)){
                int t=m[input[i]+k];
                for(int j=1;j<=t;j++)
                    cout<<(input[i])<<" "<<(input[i]+k)<<endl;
            }
            if(m.count(input[i]-k)){
             
                int t=m[input[i]-k];
                for(int j=1;j<=t;j++)
                    cout<<(input[i]-k)<<" "<<(input[i])<<endl;
             }
        }
             
        
    }

}


#include<iostream>
using namespace std;
#include "solution.h"

int main() {
	int n;
	cin >> n;
	int *input = new int[n];
	for(int i = 0; i < n; i++){
		cin >> input[i];
	}
	int k;
	cin >> k;
	printPairs(input, n, k);
}
