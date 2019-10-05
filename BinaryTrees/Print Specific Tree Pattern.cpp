/*
Given a "complete" binary tree , print the following pattern using its all nodes.
root element
first element of second level
last element of  of second level
first element of the of the third level
last element of the third level
second element of the third level
second from last element of the third level
..... So on.
Example :
For tree :
Alt text

The pattern should be: 
1 2 3 4 7 5 6 8 15 9 14 10 13 11 12
Input Format
Line 1: Nodes in level order form (separated by space). If any node does not have left or right child, take -1 in its place
Output Format
Required pattern
Constraint
Given binary tree is complete
1 <= Number of Nodes <= 10^6
1 <= value of each node <= 10^8
Sample Input 1
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
Sample Output 1
1 2 3 4 7 5 6 8 15 9 14 10 13 11 12
*/

#include<iostream>
#include<queue>
using namespace std;


template<typename T>
class BinaryTreeNode {
    public :
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

};

#include <bits/stdc++.h>
using namespace std;

void levels(BinaryTreeNode<int>* root, vector<vector <int> > &v){
    
    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    q.push(NULL);
    
    vector <int> temp;
    while(!q.empty()){
        BinaryTreeNode<int>* curr=q.front();
        q.pop();
        
        if(curr==NULL)
            break;
        temp.push_back(curr->data);
        
        
        if(curr->left)
            q.push(curr->left);
        if(curr->right)
            q.push(curr->right);
        
        if(q.front()==NULL){
            v.push_back(temp);
            temp.clear();
            q.pop();
            q.push(NULL);
        }
    }
}

void printSpecificPattern(BinaryTreeNode<int> * root)
{
     /* Write your code here
      * Print the required pattern
      * Taking input is handled automatically
      */
    vector <vector <int> > v;
    levels(root,v);
    
    for(int i=0;i<v.size();i++){
        
        int l=0;
        int u=v[i].size()-1;
        int flag=0;
        while(l<=u){
            
            if(flag==0){
                cout<<v[i][l]<<" ";
                l++;
                flag=1;
            }
            else{
                cout<<v[i][u]<<" ";
                u--;
                flag=0;
            }
        }
    }
    
    
    
}


BinaryTreeNode<int> * takeinputlevelwise()
     {

    queue<BinaryTreeNode<int>*> pendingnodes;
    int rootdata;
    cin>>rootdata;
    if(rootdata == -1)
        return NULL;

    BinaryTreeNode<int> * root = new BinaryTreeNode<int>(rootdata);

    pendingnodes.push(root);


    while(!pendingnodes.empty())
    {

        BinaryTreeNode<int> * frontnode = pendingnodes.front();
        BinaryTreeNode<int> * currentnode = frontnode;
        pendingnodes.pop();

        int lchild;
        cin>>lchild;

        if(lchild!=-1)
        {
            BinaryTreeNode<int> * leftchild = new BinaryTreeNode<int>(lchild);
            pendingnodes.push(leftchild);
            currentnode->left = leftchild;

        }

        int rchild;
        cin>>rchild;

        if(rchild!=-1)
        {
            BinaryTreeNode<int> * rightchild = new BinaryTreeNode<int>(rchild);
            pendingnodes.push(rightchild);
            currentnode->right = rightchild;
        }


    }
    return root;
}

int main()
{
    BinaryTreeNode<int> * root = NULL;
    root = takeinputlevelwise();
    printSpecificPattern(root);
}


