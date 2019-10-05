/*
You are given two integers N and i. You need to make ith bit of binary representation of N to 0 and return the updated N.
Counting of bits start from 0 from right to left.
Input Format :

Two integers N and i (separated by space)

Output Format :

Updated N

Sample Input 1 :

7 2

Sample Output 1 :

3

Sample Input 2 :

12 1

Sample Output 2 :

12

*/

int turnOffIthBit(int n, int i){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    int ans=n;
    if((n | (1<<i))==n)
        ans=n ^ (1<<i);
    return ans;
}



#include <iostream>
using namespace std;

int main() {
	int n, i;

	cin >> n >> i;
	
	cout<< turnOffIthBit(n, i) <<endl;
		
	return 0;
}

