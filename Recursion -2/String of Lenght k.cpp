/*
Given a string S and an integer k, you need to find and return all the possible strings that can be made of size k using only characters present in string S.
The characters can repeat as many times as needed.
Note : The number of output strings can be at max 1000.
Input format :

String S and Integer k (separated by space)

Output Format :

All possible strings (in different lines)

Constraints :
1 <= Length of String S <= 10
1 <= k <= 5

*/

/****
Save all the strings in the output 2D array that is passed as argument. Return the number of strings that you have saved in output as answer from this function.
That is, return number of rows that you have added in output.
****/

#include <bits/stdc++.h>
using namespace std;

void help(string s,char *inp,int k,vector<string > &ans){
    
    if(k==0){
        ans.push_back(s);
        return;
    }

    for(int i=0;i<strlen(inp);i++){
        
        string news=s+inp[i];
        
        help(news,inp,k-1,ans);
    }
    
    
}

int allStrings(char input[], int k, char output[][100]) {
    // Write your code here
    
    vector <string> ans;
    
    help("",input,k,ans);
    
    for(int i=0;i<ans.size();i++){
        strcpy(output[i],ans[i].c_str());
    }
    return ans.size();
       
    
}

#include <iostream>
#include "solution.h"
using namespace std;

int main() {
    char a[100];
    char b[1000][100];
    cin >> a;
    int k;
    cin >> k;
    int size = allStrings(a, k, b);
    for(int i = 0; i < size; i++) {
        cout << b[i] << endl;
    }
}
