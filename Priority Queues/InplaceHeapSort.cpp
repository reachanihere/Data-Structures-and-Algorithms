/*
Given an integer array of size n. Sort this array (in decreasing order) using heap sort.
Space complexity should be O(1).
Input Format :

Line 1 : Integer n, Array size
Line 2 : Array elements, separated by space

Output Format :

Array elements after sorting

Constraints :
1 <= n <= 10^6
Sample Input:

6 
2 6 8 5 4 3

Sample Output:

8 6 5 4 3 2

 */




#include <iostream>
using namespace std;

void up_heapify(int pq[],int n){
        int CI=n-1;
        while(CI>0){
            int PI=(CI-1)/2;
            
            if(pq[PI]>pq[CI]){
                int temp=pq[PI];
                pq[PI]=pq[CI];
                pq[CI]=temp;
            }
            else
                break;
            CI=PI;
        }
}

void down_heapify(int pq[],int n){
        int pIndex=0;
        int lchild=1;
        int rchild=2;
        
        while(lchild<n){
            int maxIndex=pIndex;
            
            if(pq[lchild]<pq[maxIndex])
                maxIndex=lchild;
            if(rchild<n && pq[rchild]<pq[maxIndex])
                maxIndex=rchild;
            
            if(maxIndex==pIndex)
                break;
            int temp=pq[maxIndex];
            pq[maxIndex]=pq[pIndex];
            pq[pIndex]=temp;
            
            pIndex=maxIndex;
            lchild=2*pIndex+1;
            rchild=2*pIndex+2;
        }

}


void printarr(int a[],int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
void inplaceHeapSort(int input[], int n){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Change in the given input itself.
     * Taking input and printing output is handled automatically.
     */
    
    //Assuem the first element is heap
    
    for(int i=1;i<n;i++){
        up_heapify(input,i+1);
        //printarr(input,n);
    }
    //cout<<"==========="<<endl;
    for(int i=n-1;i>=0;i--){
        int temp=input[0];
        input[0]=input[i];
        input[i]=temp;
        //printarr(input,n);
        down_heapify(input,i);
        //printarr(input,n);
        
    }
    //cout<<"==========="<<endl;

}


#include <iostream>
using namespace std;


int main() {
	
	int size;
	cin >> size;
	int *input = new int[1 + size];
	
	for(int i = 0; i < size; i++)
		cin >> input[i];
	
	inplaceHeapSort(input, size);

	for(int i = 0; i < size; i++)
		cout << input[i] << " ";
	
	return 0;
}
