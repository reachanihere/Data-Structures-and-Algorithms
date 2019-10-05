/*
Sort an array A using Quick Sort.
Change in the input array itself. So no need to return or print anything.
Input format :

Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)

Output format :

Array elements in increasing order (separated by space)

Constraints :
1 <= n <= 1000
Sample Input:

6 
2 6 8 5 4 3

Sample Output:

2 3 4 5 6 8

*/

int Partition(int a[],int l,int u){
    int pivot=a[u];
    int pIndex=l;
    
    for(int i=l;i<u;i++){
        
        if(pivot>a[i]){
            int temp=a[pIndex];
            a[pIndex]=a[i];
            a[i]=temp;
            pIndex++;
        }
    }
    int temp=a[pIndex];
    a[pIndex]=a[u];
    a[u]=temp;
    return pIndex;
}


void qS(int a[],int l,int u){
    if(l<u){
        int pIndex=Partition(a,l,u);
        qS(a,l,pIndex-1);
        qS(a,pIndex+1,u);
    }
}


void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
    qS(input,0,size-1);

}

#include<iostream>
#include "Solution.h"
using namespace std;


int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}
