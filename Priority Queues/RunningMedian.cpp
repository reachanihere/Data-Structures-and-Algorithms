/*
You are given a stream of n integers. For every ith integer, add it to the running list of integers and print the resulting median (of the list till now).
Print the only integer part of median.
Input Format :

Line 1 : An integer N denoting the number of integers in the stream
Line 2 : N integers which are separated by spaces

Output Format :

After each new integer is added to the list print the updated median on a new line

Input Constraints
1 <= n <= 10^5
1 <= Ai <= 10^5
Sample Input 1 :

6
6 2 1 3 7 5

Sample Output 1 :

6
4
2
2
3
4

Sample Output explanation :
S = {6}, median = 6
S = {6, 2} -> {2, 6}, median = 4
S = {6, 2, 1} -> {1, 2, 6}, median = 2
S = {6, 2, 1, 3} -> {1, 2, 3, 6}, median = 2
S = {6, 2, 1, 3, 7} -> {1, 2, 3, 6, 7}, median = 3
S = {6, 2, 1, 3, 7, 5} -> {1, 2, 3, 5, 6, 7}, median = 4
 */



#include<bits/stdc++.h>
using namespace std;

void findMedian(int arr[], int n){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output as specified in the question.
     */
    priority_queue<int> max_half;
    priority_queue<int,vector<int>,greater<int> > min_half;
    
    
    for(int i=0;i<n;i++){
        
        if(max_half.empty()){
            max_half.push(arr[i]);
            cout<<arr[i]<<endl;
            continue;
        }
        
        if(arr[i]<max_half.top()){
            max_half.push(arr[i]);
            
            if(max_half.size()- min_half.size()>1){
                min_half.push(max_half.top());
                max_half.pop();
            }
            if((i+1)%2==0){
                int x=(max_half.top()+min_half.top())/2;
                cout<<x<<endl;
            }
            else{
                if(max_half.size()>min_half.size())
                    cout<<max_half.top()<<endl;
                else
                    cout<<min_half.top()<<endl;
            }
        }
        else{
            min_half.push(arr[i]);
            
            if(min_half.size()-max_half.size()>1){
                max_half.push(min_half.top());
                min_half.pop();
            }
            if((i+1)%2==0){
                int x=(max_half.top()+min_half.top())/2;
                cout<<x<<endl;
            }
            else{
                if(max_half.size()>min_half.size())
                    cout<<max_half.top()<<endl;
                else
                    cout<<min_half.top()<<endl;;
            }
        }
    }
    

}



#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    findMedian(arr, n);
    
    delete [] arr;
    
}