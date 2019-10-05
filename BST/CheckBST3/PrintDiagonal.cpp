/*
Given a binary tree, print all the diagonal elements in a binary tree belonging to same line with slope equal to -1.
For eg.

Alt text
Input format :

Elements in level order form (separated by space) 
(If any node does not have left or right child, take -1 in its place) 

Output Format :

Elements are printed diagonally,(separated by space). Each diagonal level in new line.

Sample Input 1:

8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1 

Sample Output 1:

8 10 14
3 6 7 13
1 4

 */


#include <bits/stdc++.h>
using namespace std;

void diag(BinaryTreeNode<int>* root,int diagonal,unordered_map <int,vector<int> > &m){
    
    if(root==NULL)
        return;
    
    m[diagonal].push_back(root->data); //Take note of hash map approach. Very useful in finding boundary traversals
    
    diag(root->left,diagonal+1,m);
    diag(root->right,diagonal,m);
    
}


void printV(vector <int> &v){
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" "; 
}
void PrintDiagonal(BinaryTreeNode<int>* root) {
	// Don't write main().
	// Write your code here.
    unordered_map <int,vector<int> > m;
    
    diag(root,0,m);
    
    for(int i=0;i<m.size();i++){
        printV(m[i]);
        cout<<endl;
    }
}


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

BinaryTreeNode<int>* takeInputLevelWise(){
    queue< BinaryTreeNode<int>*  > pendingNodes;
    int rootData;
    cin >> rootData;
    
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    pendingNodes.push(root);
    
    while(!pendingNodes.empty()){
        BinaryTreeNode<int>* currentNode =  pendingNodes.front();
        pendingNodes.pop();
        int leftData;
        cin >> leftData;
        if(leftData != -1 ){
            BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(leftData);
            pendingNodes.push(leftChild);
            currentNode->left = leftChild;
        }
        int rightData;
        cin >> rightData;
        if(rightData != -1 ){
            BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(rightData);
            pendingNodes.push(rightChild);
            currentNode->right = rightChild;
        }
    }
    return root;
}


void printlevelwise(BinaryTreeNode<int> *root)
{
    if(root==NULL){
        return;
    }
    queue<BinaryTreeNode<int>* >pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(0);
    cout<<root->data<<endl;
    BinaryTreeNode<int>* top=NULL;
    while(!pendingNodes.empty())
    {
        BinaryTreeNode<int>*q1=pendingNodes.front();
        pendingNodes.pop();
        BinaryTreeNode<int>*q2=pendingNodes.front();
        if(q1==0)
        {
            return;
        }
        if(q2==0)
        {
            pendingNodes.pop();
        }
        if (q1->left!=0)
        {
            pendingNodes.push(q1->left);
            cout<<q1->left->data<<' ';
        }
        if(q1->right!=0)
        {
            pendingNodes.push(q1->right);
            cout<<q1->right->data<<' ';
            if(q2==0)
            {
                pendingNodes.push(0);
            }
        }
        else
        {
            if(q2==0)
            {
                pendingNodes.push(0);
            }
        }
        if(q2==0)
        {
            cout<<endl;
        }
    }
}



int main()
{
	BinaryTreeNode<int>*root=takeInputLevelWise();
	PrintDiagonal(root);
}
