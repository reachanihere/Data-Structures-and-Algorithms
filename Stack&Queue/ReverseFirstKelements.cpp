/*
Given a queue and an integer k, reverse first k elements. Return the updated queue.
Do the problem in O(n) complexity.
Input Format :

Line 1 : Integer N, Size of Queue
Line 2 : Queue Elements (separated by space)
Line 3 : Integer k

Output Format:

Updated Queue elements

Contraints :
1<= N <=10000
Sample Input 1:

5
1 2 3 4 5
3

Sample Output 1:

3 2 1 4 5

Sample Input 2:

7
3 4 2 5 6 7 8
7

Sample Output 2:

8 7 6 5 2 4 3

 */


#include <cmath>
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

queue<int> reverseKElements(queue<int> input, int k) {
	/* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    stack<int> rev;
    queue<int> tem;
    
    int c=0;
    while(!input.empty())
    {
        if(c<k)
        {
            rev.push(input.front());
            c++;
        }
        else
        {
            tem.push(input.front());
        }
        input.pop();
    }
    queue<int> out;
    
    while(!rev.empty())
    {
        out.push(rev.top());
        rev.pop();
    }
    while(!tem.empty())
    {
        out.push(tem.front());
        tem.pop();
    }
    return out;
    
}


int main() {
	int n=0;
	cin>>n;
	queue<int> Queue;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		Queue.push(temp);
	}
	int k;
	cin>>k;
	
	queue<int> ans = reverseKElements(Queue,k);
	while (!ans.empty()) {
        	cout << ans.front() << endl;
        	ans.pop();
    	}
}
