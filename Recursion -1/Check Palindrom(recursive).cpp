/*
Check if a given String S is palindrome or not (using recursion). Return true or false.
Input Format :

String S

Output Format :

true or false

Sample Input 1 :

racecar

Sample Output 1:

true

Sample Input 2 :

ninja

Sample Output 2:

false

*/

#include <bits/stdc++.h>
using namespace std;
bool chp(char input[],int start,int end){
    if(end<start)
        return true;
    if(input[start]!=input[end])
        return false;
    
    bool ans=chp(input,start+1,end-1);
    return ans;
}
bool checkPalindrome(char input[]) {
    // Write your code here
    int end=strlen(input)-1;
    return chp(input,0,end);
    
}


#include <iostream>
#include "solution.h"
using namespace std;

int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
