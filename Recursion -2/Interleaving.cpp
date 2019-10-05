/*
Given two strings S (of length m) and T (of length n), you need to find and print out all the possible inter leavings that are possible of length (m + n).
Inter leaving means - all possible combination of characters from both strings such that it contain all characters from both strings and, the respective ordering of characters of one string should remain same as in original.
For eg.

S = ab
T = cd

You need to find all strings of length 4 that contain all characters 'a', 'b', 'c' & 'd'. The only constraint on ordering of characters is - 'a' should always come before 'b' and 'c' should always come before 'd'.
Note : Print all strings in different lines.
Sample Input :

abc
def

Sample Output :

abcdef
abdcef
abdecf
abdefc
adbcef
adbecf
adbefc
adebcf
adebfc
adefbc
dabcef
dabecf
dabefc
daebcf
daebfc
daefbc
deabcf
deabfc
deafbc
defabc

*/

#include <bits/stdc++.h>
using namespace std;

void printinter(char * first,char *second,string out){
    
    if(first[0]=='\0'){
        cout<<(out+second)<<endl;
        return;
    }
    if(second[0]=='\0'){
        cout<<(out+first)<<endl;
        return;
    }
    
    printinter(first+1,second,out+first[0]);
    printinter(first,second+1,out+second[0]);
}

void interleaving(char* first, char* second) {
	// Write your code here
    string out="";
    printinter(first,second,out);
    
}

#include <iostream>
using namespace std;
#include "solution.h"

int main() {
    char *a = new char[1000];
    char *b = new char[1000];
    cin >> a;
    cin >> b;
    interleaving(a, b);
}
