/*
Given an integer n, print all n digit increasing numbers in increasing order in one line.
Numbers you need to print should be in increasing order and only those numbers should be printed which have digits in increasing order.
Input Format :

Integer n

Output Format :

 Numbers in increasing order

Constraints :
1 <= n <= 8
Sample Input :

2

Sample Output :

12 13 14 15 16 17 18 19 23 24 25 26 27 28 29 34 35 36 37 38 39 45 46 47 48 49 56 57 58 59 67 68 69 78 79 89 
*/

#include <bits/stdc++.h>
using namespace std;

void helper(int number,int x,int k){
    if(k==0){
        cout<<number<<" ";
        return;
    }
    
    for(int i=(x+1);i<=9;i++){
        helper(number*10+i,i,k-1);
    }
}

void printIncreasingNumbers(int n) {
	
	/* Don't write main().
 	Don't read input, it is passed as function argument.
	Print the required output
	*/
    helper(0,0,n);
    
    

}

#include<iostream>
using namespace std;
#include "solution.h"

int main()
{
	int n;
	cin>>n;
  printIncreasingNumbers(n);
}
