/*
Given an array of integers, check whether it represents max-heap or not.
Return true or false.
Input Format :

Line 1 : An integer N i.e. size of the array
Line 2 : N integers which are elements of the array, separated by spaces

Output Format :

true if it represents max-heap and false if it is not a max-heap

Constraints :
1 <= N <= 10^5
1 <= Ai <= 10^5
 */


bool checkMaxHeap(int arr[], int n){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Taking input and printing output is handled automatically.
     */
    
    int p=0;
    int lc=1;
    int rc=2;
    while(lc<n){
        
        if(arr[p]<arr[lc])
            return false;
        
        if(rc<n && arr[p]<arr[lc])
            return false;
        p++;
        lc=2*p+1;
        rc=2*p+2;
    }
    return true;
}



#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    bool ans = checkMaxHeap(arr, n);
    if(ans){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    
    delete [] arr;
}
