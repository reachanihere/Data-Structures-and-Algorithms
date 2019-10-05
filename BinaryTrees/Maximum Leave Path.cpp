/*
Given a binary tree of N nodes, find and return the maximum sum path between two leaves of the given tree.
Given binary tree contains positive values only.
Input format :
Line 1 : Nodes in level order form (separated by space). If any node does not have left or right child, take -1 in its place
Output format :
Maximum sum path
Constraints :
1 <= N <= 10^5
Sample Input :
10 9 4 3 1 5 8 -1 -1 -1 -1 -1 6 -1 -1 3 -1 -1 -1
Sample Output :
40
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
};

using namespace std;




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


long long int lsum(BinaryTreeNode<int>* root){
    
    if(root==NULL)
        return 0;
    
    return root->data+max(lsum(root->left),lsum(root->right));
}

void trav(BinaryTreeNode<int> *root,long long int &msum){
    
    if(root==NULL)
        return;
    
    long long ans=root->data+lsum(root->left)+lsum(root->right);
    msum=max(msum,ans);
    
    trav(root->left,msum);
    trav(root->right,msum);
}

long long int maximumSumLeafpath(BinaryTreeNode<int> *root){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    long long int msum=0;
    trav(root,msum);
    
    return msum;
    
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
    cout << maximumSumLeafpath(root) << endl;
}