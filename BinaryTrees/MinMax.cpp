/*
Given a binary tree, find and return the min and max data value of given binary tree.
Return the output as an object of PairAns class, which is already created.
Input format :
Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)
Output Format :
Max and min (separated by space)
Sample Input :
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
Sample Output :
14 1
*/

#include <iostream>
#include <queue>
using namespace std;

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
};

class PairAns {
    public :
    int min;
    int max;
    PairAns(){
        min=INT_MAX;
        max=INT_MIN;
    }
};



// Following is the Binary Tree node structure
/**************
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
 
 // PairAns class -
 class PairAns {
    public :
        int min;
        int max;
 };
 
***************/

#include <bits/stdc++.h>
using namespace std;

void trav(BinaryTreeNode<int>* root,int &minx,int &maxx){
    
    if(root==NULL)
        return;
    
    minx=min(minx,root->data);
    maxx=max(maxx,root->data);
    
    trav(root->left,minx,maxx);
    trav(root->right,minx,maxx);
}

PairAns minMax(BinaryTreeNode<int> *root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    int minx=INT_MAX;
    int maxx=INT_MIN;
    
    trav(root,minx,maxx);
    
    PairAns p;
    p.min=minx;
    p.max=maxx;
    return p;

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
    PairAns ans = minMax(root);
    cout << ans.max << " " << ans.min << endl;
}


