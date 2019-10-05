/*
You are given with an integer k and an array of integers that contain numbers in random order. Write a program to find k smallest numbers from given array. You need to save them in an array and return it.
Time complexity should be O(nlogk) and space complexity should be not more than O(k).
Order of elements in the output is not important.
Input Format :

Line 1 : Size of array (n)
Line 2 : Array elements (separated by space)
Line 3 : Integer k

Output Format :

k smallest elements

Sample Input 1 :

13
2 12 9 16 10 5 3 20 25 11 1 8 6 
4

Sample Output 1 :

5
3
2
1

 */


#include <queue>
using namespace std;


vector<int> kSmallest(int *input, int n, int k) {
	// Write your code here
    priority_queue<int> pq;
    vector <int>ans;
    
    for(int i=0;i<k;i++)
        pq.push(input[i]);
    
    for(int i=k;i<n;i++){
        
        if(input[i]<pq.top()){
            pq.pop();
            pq.push(input[i]);
        }
    }
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}


#include<iostream>
using namespace std;
#include <vector>

int main() {
	int n;
	cin >> n;
	int *input = new int[n];
	for(int i = 0; i < n; i++){
		cin >> input[i];
	}
	int k;
	cin >> k;
	vector<int> output = kSmallest(input, n, k);
	for(int i = 0; i < output.size(); i++){
		cout << output[i] << endl;
	}
}
