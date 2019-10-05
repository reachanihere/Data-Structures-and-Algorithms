/*
You are given an integer N. You need to check if N is power of 4 or not. Return true or false accordingly.
Note : Do it in O(1) time.
Input Format :

Integers N 

Output Format :

true or false

Sample Input 1 :

4

Sample Output 1 :

true

Sample Input 2 :

8

Sample Output 2 :

false

 */

bool isPowerOf4(int n){
    
    bool ans=!(n&(n-1)) && (n & 0x5555555);
    return ans;
    
}

#include <iostream>
using namespace std;

int main() {
	int n;

	cin >> n;
	
    if(isPowerOf4(n)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
		
	return 0;
}



