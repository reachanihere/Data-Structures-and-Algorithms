/*
Given an array A of random integers and an integer k, find and return the kth largest element in the array.
Try to do this question in less than O(nlogn) time.
Input Format :

Line 1 : An integer N i.e. size of the array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : An integer k

Output Format :

kth largest element

Input Constraints :
1 <= N, Ai, k <= 10^5
Sample Input 1 :

6
9 4 8 7 11 3
2

Sample Output 1 :

9

Sample Input 2 :

8
2 6 10 11 13 4 1 20
4

Sample Output 2 :

10

 */

#include <iostream>
#include <vector>
using namespace std;

int kthLargest (vector<int> arr, int n, int k){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    priority_queue<int,vector<int>,greater<int> > pq;
    
    for(int i=0;i<k;i++)
        pq.push(arr[i]);
    
    for(int i=k;i<n;i++){
        
        if(arr[i]>pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    while(pq.size()==1){
        pq.pop();
    }
    return pq.top();
    
}




int main(){
    int n, k, s;
    vector<int> arr;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>s;
        arr.push_back(s);
    }
    cin >> k;
    cout << kthLargest(arr, n, k) << endl;
}
