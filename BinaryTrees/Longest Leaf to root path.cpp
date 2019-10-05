/*
Given a binary tree, return the longest path from leaf to root. Longest means, a path which contain maximum number of nodes from leaf to root.
Input format :

Elements in level order form (separated by space)

(If any node does not have left or right child, take -1 in its place)

Line 1 : Binary Tree 1 (separated by space)

Sample Input 1 :
 5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1 :
9
3
6
5
*/

#include <iostream>
#include <vector>
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


//Alternative Approach is to non referencing variable for v. In that case v.pop_back() won't be needed
void help(BinaryTreeNode<int>* root,vector <int> &v,vector<int> &ans){
    
    if(root==NULL){
        if(v.size()>ans.size())
            ans=v;
        return;
    }
    v.push_back(root->data);
    help(root->left,v,ans);
    help(root->right,v,ans);
    v.pop_back();
}

vector<int>* longestPath(BinaryTreeNode<int>* root) {
	// Write your code here
    vector <int> v;
    vector <int> ans;
    
    help(root,v,ans);
    
    vector <int>* p=new vector<int>; //Take a note of this
    for(int i=ans.size()-1;i>=0;i--)
     {
         int k=ans[i];
         p->push_back(k);
     }
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
    vector<int> *output = longestPath(root);
    vector<int> :: iterator i = output -> begin();
    while(i != output -> end()) {
    	cout << *i << endl;
    	i++;
    }
}
