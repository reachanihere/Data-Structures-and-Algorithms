/*
Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".
Sample Input 1 :

xpix

Sample Output :

x3.14x

Sample Input 2 :

pipi

Sample Output :

3.143.14

Sample Input 3 :

pip

Sample Output :

3.14p

*/

#include <bits/stdc++.h>
using namespace std;
// Change in the given string itself. So no need to return or print anything

void replacePi(char input[]) {
	// Write your code here
    if(input[0]=='\0')
        return;
    if(input[0]=='p' && input[1]=='i'){
        input[0]='3';
        input[1]='.';
        
        int size=strlen(input);
        for(int i=size+2;i>1;i--){
            input[i]=input[i-2];
        }
        input[2]='1';
        input[3]='4';
    }
    
    replacePi(input+1);

}


#include <iostream>
#include "solution.h"
using namespace std;

int main() {
    char input[100];
    cin.getline(input, 100);
    replacePi(input);
    cout << input << endl;
}
