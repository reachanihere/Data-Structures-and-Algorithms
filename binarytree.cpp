#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int val;
    node *left;
    node *right;
};

void printtree(node *root){
    cout<<root->val<<" ";
    if(root==NULL)
    {  return;
    }
    printtree(root->left);
    printtree(root->right);
    return;
}

node* addnode(int value,node *root){
    if(root==NULL)
    {  node* newnode =new node;
        root=newnode;
        newnode->val=value;
        return ;
    }
    if(root->left==NULL){
        node* newnode =new node;
        root->left=newnode;
        newnode->val=value;
        return;
    }
    if(root->right==NULL){
          node* newnode =new node;
        root->right=newnode;
        newnode->val=value;
       
        return;
    }
    addnode(value,root->left);
    addnode(value,root->right);
    return;
}

int main(){

int arr[]={1,2,3,5,6};
node *root=NULL;
node *head=
for(int i=0;i<5;i++)
{
    addnode(arr[i],root);
}
printtree(root);
return 0;
}