/*
Given a BST and an integer K, you need to find the Kth smallest element present in the BST. Return INT_MIN if that is not present in the BST.
Input format :

Line 1: Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)

Output Format:

Line 1: Kth smallest node

Sample Input :

8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
3

Sample Output :

6

 */

#include <iostream>
#include <queue>

template <typename T>
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

    ~BinaryTreeNode() {
    	if(left) 
    	    delete left;
    	if(right) 
    	    delete right;
    }
};

#include <bits/stdc++.h>
using namespace std;

void inOrder(BinaryTreeNode<int>* root,vector <int> &v){
    if(root==NULL)
        return;
    
    inOrder(root->left,v);
    v.push_back(root->data);
    inOrder(root->right,v);
}


int findNode(BinaryTreeNode<int>* root, int k) {
		// Write your code here

    vector <int>v;
    inOrder(root,v);
    
    if(k>v.size())
        return INT_MIN;
    else
        return v[k-1];
}

BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int k;
    cin >> k;
    cout << findNode(root, k);
    delete root;
}