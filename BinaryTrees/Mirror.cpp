/*
Mirror the given binary tree. That is, right child of every nodes should become left and left should become right.

Alt text
Note : You don't need to print or return the tree, just mirror it.

Input format :

Line 1 : Elements in level order form (separated by space)

(If any node does not have left or right child, take -1 in its place)

Output format : Elements in level order form (Every level in new line)
Sample Input 1:

1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1

Sample Output 1:

1 
3 2 
7 6 5 4

Sample Input 2:

5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1

Sample Output 2:

5 
6 10 
3 2 
9

 */

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


void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    // Write your code here
    if(root==NULL)
        return;
    
    BinaryTreeNode<int>* temp=root->left;
    root->left=root->right;
    root->right=temp;
    
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);

}


#include <iostream>
#include <queue>


using namespace std;

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
    BinaryTreeNode<int>* root = takeInput();
    mirrorBinaryTree(root);
    printLevelATNewLine(root); 	
}
