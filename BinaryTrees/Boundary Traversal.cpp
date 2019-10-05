/*
Given a binary tree having N nodes, print its boundary traversal.
Input format :
Line 1 : Nodes in level order form (separated by space). If any node does not have left or right child, take -1 in its place
Output format :
Boundary traversal (separated by space)
Constraints :
1 <= N <= 10^5
Sample Input 1 :
1 2 3 -1 -1 -1 -1
Sample Output 1 :
1 2 3
Sample Input 2 :
1 2 3 4 5 7 -1 -1 -1 6 -1 -1 8 -1 -1 -1 -1
Sample Output 2 :
1 2 4 6 8 7 3
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
***************/
void leftBound(BinaryTreeNode<int>* root,vector <int> &v){
    
    if(root->left==NULL && root->right==NULL)
        return;
    v.push_back(root->data);
    
    if(root->left!=NULL)
        leftBound(root->left,v);
    else if(root->right !=NULL)
        leftBound(root->right,v);
    
}

void rightBound(BinaryTreeNode<int>* root,vector <int> &v){
    
    if(root->left==NULL && root->right==NULL)
        return;
    
    if(root->right!=NULL)
        rightBound(root->right,v);
    else if(root->left !=NULL)
        rightBound(root->left,v);
    
    v.push_back(root->data);
    
}

void leafBound(BinaryTreeNode<int>* root,vector <int> &v){
    
    if(root==NULL)
        return;
    if(root->left==NULL && root->right==NULL){
        v.push_back(root->data);
        return;
    }
        
    leafBound(root->left,v);
    leafBound(root->right,v);
        
}


void solve(BinaryTreeNode<int>* root){
    	/* Don't write main().
	* Don't read input, it is passed as function argument.
	*/
    vector <int> v;
    leftBound(root,v);
    leafBound(root,v);
    rightBound(root,v);
    v.pop_back();
    
    
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    
    
    

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
    solve(root);
}
