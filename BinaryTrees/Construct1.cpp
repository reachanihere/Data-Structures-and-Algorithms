/*
Given Preorder and Inorder traversal of a binary tree, create the binary tree associated with the traversals.You just need to construct the tree and return the root.
Note: Assume binary tree contains only unique elements.
Input format :

Line 1 : n (Total number of nodes in binary tree)

Line 2 : Pre order traversal

Line 3 : Inorder Traversal

Output Format :

Elements are printed level wise, each level in new line (separated by space).

Sample Input :
12
1 2 3 4 15 5 6 7 8 10 9 12
4 15 3 2 5 1 6 10 8 7 9 12
Sample Output :
1 
2 6 
3 5 7 
4 8 9 
15 10 12
*/

#include <iostream>
#include <queue>


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
#include <iostream>
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

int searchroot(BinaryTreeNode<int>* root ,int *inorder,int inLength){
    
    for(int i=0;i<inLength;i++)
        if(root->data==inorder[i])
            return i;
    return -1;
}

BinaryTreeNode<int>* buildTree(int *preorder, int preLenght, int *inorder, int inLength) {
    // Write your code here
    if(preLenght==0)
        return NULL;
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(preorder[0]);

    int pos=searchroot(root,inorder,inLength);
    int newLInlength=pos;
    int newRInlength=inLength-(pos+1);

    int newLpreLength=newLInlength;
    int newRpreLenght=newRInlength;

    BinaryTreeNode<int>* left=buildTree(preorder+1,newLpreLength,inorder,newLInlength);
    BinaryTreeNode<int>* right=buildTree(preorder+newLInlength+1,newRpreLenght,inorder+pos+1,newRInlength);

    root->left=left;
    root->right=right;

    return root;

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

void printLevelATNewLine(BinaryTreeNode<int> *root) {
		queue<BinaryTreeNode<int>*> q;
		q.push(root);
		q.push(NULL);
		while(!q.empty()) {
			BinaryTreeNode<int> *first = q.front();
			q.pop();
			if(first == NULL) {
				if(q.empty()) {
					break;
				}
				cout << endl;
				q.push(NULL);
				continue;
			}
			cout << first -> data << " ";
			if(first -> left != NULL) {
				q.push(first -> left);
			}
			if(first -> right != NULL) {
				q.push(first -> right);
			}
		}
}

int main() {
    int size;
    cin >> size;
    int *pre = new int[size];
    int *in = new int[size];
    for(int i=0;i<size;i++)
		cin>>pre[i];
    for(int i=0;i<size;i++)
		cin>>in[i];
    BinaryTreeNode<int>* root = buildTree(pre, size, in, size);
    printLevelATNewLine(root);
}
