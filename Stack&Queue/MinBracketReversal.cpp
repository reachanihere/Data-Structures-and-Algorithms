/*
Given a string expression which consists only ‘}’ and ‘{‘. The expression may not be balanced. You need to find the minimum number of bracket reversals which are required to make the expression balanced.
Return -1 if the given expression can't be balanced.
Input Format :

String S

Output Format :

Required count

Sample Input 1 :

{{{

Sample Output 1 :

-1

Sample Input 2 :

{{{{}}

Sample Output 2 :

1

*/


#include <stack>
using namespace std;
int countBracketReversals(char input[]){
	// Write your code here
    stack <char> s;
    for(int i=0;input[i]!='\0';i++){
        if(input[i]=='{')
            s.push('{');
        else{
            if(!s.empty() && s.top()=='{')
                s.pop();
            else
                s.push('}');
        }
    }
    int c=s.size();
    //cout<<ans<<endl;
    if(c & 1)
        return -1;
    int ans=0;
    
    while(!s.empty())
    {
        char c1=s.top();
        s.pop();
        char c2=s.top();
        s.pop();
        
        if( c2=='}' && c1=='{')
            ans+=2;
        else
            ans+=1;
    }
    return ans;

}

#include <iostream>

int main() {
    char input[10000];
    cin >> input;
    cout << countBracketReversals(input) << endl;
}