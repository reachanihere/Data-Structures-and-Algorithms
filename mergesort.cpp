#include<bits/stdc++.h>
using namespace std;
void selectionsort(int * arr,int n)
{

    for(int i=0;i<n;i++)
    {   int m= arr[i];
        int index=i;
        for(int j= i+1;j<n;j++)
        {
            if(m>arr[j]){m=arr[j];index=j;}
        }
        swap(arr[i],arr[index]);
    }
    return;
}
  
void bubblesort(int *arr, int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }
}

void printArray(int *arr,int n){
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;

    return;
}
int main(){
    int arr[]={1,4,3,5,23,55,22,3};
    // selectionsort(arr,8);
    bubblesort(arr,8);
    printArray(arr,8);
}