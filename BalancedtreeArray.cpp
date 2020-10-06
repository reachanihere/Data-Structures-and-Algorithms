#include<bits/stdc++.h>
using namespace std;


///for trees
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    node* left;
    node* right;
    int data;

    node(int d)
    {
        left=NULL;
        right=NULL;
        data=d;
    }
};

node* buildtree(){
    int d;
    cin>>d;
    if(d==-1)
    {
        return NULL;
    }
    node* root = new node(d);
    root->left = buildtree();
    root->right=buildtree();

    return root;
}
node* buildbalancedtree(int arr[],int s,int e){
    if(s>e)
    return NULL;

    int mid = (s+e)/2;

    node* root = new node(arr[mid]);
    root->left = buildbalancedtree(arr,s,mid-1);
    root->right = buildbalancedtree(arr,mid+1,e);

    return root;


}
// the the was #incluide<iostream>
// THis value

int main()
{
    //node* root=buildtree();
    int arr[]={1,2,3,4,5,6,7};
    int size = sizeof(arr)/sizeof(int);
    buildbalancedtree(arr,0,size-1);

    return 0;
}