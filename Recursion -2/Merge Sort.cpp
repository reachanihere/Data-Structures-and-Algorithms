/*
Sort an array A using Merge Sort.
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


void merge(int a[],int l,int mid,int u){
    
    int size1=mid-l+1;
    int size2=u-mid;
    
    int L1[size1];
    int L2[size2];
    
    int k=0;
    for(int i=l;i<=mid;i++,k++)
        L1[k]=a[i];
    int j=0;
    for(int i=mid+1;i<=u;i++,j++)
        L2[j]=a[i];
    k=0;
    j=0;
    int i=l;
    while(k<size1 && j <size2){
        
        if(L1[k]<=L2[j]){
            a[i]=L1[k++];
            i++;
        }
        else{
            a[i]=L2[j++];
            i++;
        }
    }
    
    while(k<size1){
        a[i]=L1[k++];
        i++;
    }
    while(j<size2){
        a[i]=L2[j++];
        i++;
    }
    
}
void mS(int a[],int l,int u){
    
    if(l<u){
        int mid=(l+u)/2;
        mS(a,l,mid);
        mS(a,mid+1,u);
        merge(a,l,mid,u);
    }
}

void mergeSort(int input[], int size){
	// Write your code here
    int l=0;
    int u=size-1;
    
    mS(input,l,u);
        
}


#include <iostream>
#include "solution.h"
using namespace std;

int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}
