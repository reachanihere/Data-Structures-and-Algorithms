/*
Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.
Input format :

Numeric string (string, Eg. "1234")

Output format :

Corresponding integer (int, Eg. 1234)

Sample Input 1 :

1231

Sample Output 1:

1231

Sample Input 2 :

12567

Sample Output 2 :

12567
*/

#include <bits/stdc++.h>
using namespace std;
int stringToNumber(char input[]) {
    // Write your code here
    if (input[0]=='\0')
        return 0;
    int ans=stringToNumber(input+1);
    
    int size=strlen(input);
    int d=(input[0]-48)*pow(10,size-1);
    return ans+d;

}



#include <iostream>
#include "solution.h"
using namespace std;

int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
