/*
Given n pairs of parentheses, write a function to generate and print all combinations of well-formed parentheses. That is, you need to generate all possible valid set of parenthesis that can be formed with given number of pairs.
Input format :

Integer n

Output format :

Print all possible valid parenthesis in different lines

Note: Order in which different combinations of well-formed parentheses are printed in different lines doesn't matter.
Constraints :
1 <= n <= 10
Sample Input :

3

Sample Output :

((()))
(()())
(())()
()(())
()()()

*/


void help(int pos,int n ,int open, int close){
    static char str[1000];
    
    if(close==n){
        cout<<str<<endl;
        return;
    }
    else{
        if(open>close){
            str[pos]=')';
            help(pos+1,n,open,close+1);
        }
        if(open<n){
            str[pos]='(';
            help(pos+1,n,open+1,close);
        }
    }
}



void printWellFormedParanthesis(int n){
    // Write your code here
    help(0,n,0,0);

}

#include <iostream>
using namespace std;
#include "solution.h"

int main() {
    int n;
    cin >> n;
    printWellFormedParanthesis(n);
}
