/*
Given a random integer array A of size N. Find and print the pair of elements in the array which sum to 0.
Array A can contain duplicate elements.
While printing a pair, print the smaller element first.
That is, if a valid pair is (6, -6) print "-6 6". There is no constraint that out of 5 pairs which have to be printed in 1st line. You can print pairs in any order, just be careful about the order of elements in a pair.
Input format :

Line 1 : Integer N (Array size)
Line 2 : Array elements (separated by space)

Output format :

Line 1 : Pair 1 elements (separated by space)
Line 2 : Pair 2 elements (separated by space)
Line 3 : and so on

Constraints :
1 <= N <= 10^6
Ai contains all non-zero values
Sample Input:

5
2 1 -2 2 3

Sample Output :

-2 2
-2 2


*/

#include <bits/stdc++.h>
using namespace std;

void PairSum(int *input, int n) {	 
		
	/* Don't write main().
     	* the input array is already passed as function argument.
     	* Don't need to return anything. Print the desired pairs in the function itself.
     	*/
    // Key=Element, Value=frequency, index
    unordered_map <int,int > m;
    
    for(int i=0;i<n;i++){
        if(m.count(input[i])==0)
            m[input[i]]=1;
        else
            m[input[i]]+=1;
        
        if(m.count(-input[i])){
            for(int j=1;j<=m[-input[i]];j++){
                int a,b;
                if(input[i]>0){
                    a=-input[i];
                    b=input[i];
                }
                else{
                    a=input[i];
                    b=-input[i];
                }
                cout<<a<<" "<<b<<endl;
            }
        }

    }
}

#include<iostream>
using namespace std;
#include "solution.h"

int main()
{
    int n;
    int arr[100000];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    PairSum(arr, n);
    return 0;
}
