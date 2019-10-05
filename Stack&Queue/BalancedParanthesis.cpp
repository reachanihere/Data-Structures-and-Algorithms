/*
Given a string expression, check if brackets present in the expression are balanced or not. Brackets are balanced if the bracket which opens last, closes first.
You need to return true if it is balanced, false otherwise.
Note: This problem was asked in initial rounds in Facebook
Sample Input 1 :

{ a + [ b+ (c + d)] + (e + f) }

Sample Output 1 :

true

Sample Input 2 :

{ a + [ b - c } ]

Sample Output 2 :

false


*/

#include <stack>
#include <iostream>
using namespace std;
bool checkBalanced(char *exp) {
	// Write your code here
    stack <char> c;
    
    for(int i=0;exp[i]!='\0';i++){
        
        if(exp[i]=='{' || exp[i]=='[' || exp[i]=='(')
            c.push(exp[i]);
        
        if(exp[i]=='}'){
            if(!c.empty() && c.top()=='{')
                c.pop();
            else
                return false;
        }
        if(exp[i]==']'){
            if(!c.empty() && c.top()=='[')
                c.pop();
            else
                return false;
        }
        if(exp[i]==')'){
            if(!c.empty() && c.top()=='(')
                c.pop();
            else
                return false;
        }
    }
    if(!c.empty())
        return false;
    return true;

}

int main() {
    char input[100000];
    cin.getline(input, 100000);
//    cin >> input;
    if(checkBalanced(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
