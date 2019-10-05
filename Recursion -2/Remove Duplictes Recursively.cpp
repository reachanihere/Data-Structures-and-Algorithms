/*
Given a string S, remove consecutive duplicates from it recursively.
Input Format :

String S

Output Format :

Output string

Constraints :
1 <= Length of String S <= 10^3
Sample Input :

aabccba

Sample Output :

abcba

*/

void removeConsecutiveDuplicates(char *input) {
	/* Don't write main().
	* Don't read input, it is passed as function argument.    
	* Change in the given string itself.
	* No need to return or print anything
	* Taking input and printing output is handled automatically.
	*/

    if(input[0]=='\0')
        return;
    if(input[0]==input[1]){
        int i=1;
        for(;input[i]!='\0';i++)
            input[i-1]=input[i];
        input[i-1]=input[i];
        removeConsecutiveDuplicates(input);
    }
    removeConsecutiveDuplicates(input+1);

}
#include <iostream>
using namespace std;
#include "solution.h"

int main() {
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}