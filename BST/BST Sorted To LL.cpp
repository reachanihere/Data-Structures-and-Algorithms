/*
Given a BST, convert it into a sorted linked list. Return the head of LL.
Input format :

Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)

Output Format :

Linked list elements (separated by space)

Sample Input :

8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1

Sample Output :

2 5 6 7 8 10

 */



#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class Node{
public:
    T data;
    Node<T> *next;
    Node(T data){
        this -> data = data;
        this -> next = NULL;
    }
};

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
 
 template <typename T>
 class Node{
    public:
    T data;
    Node<T> *next;
    
    Node(T data){
        this -> data = data;
        this -> next = NULL;
    }
 };
 
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

pair <Node<int>*,Node<int>*> help(BinaryTreeNode<int>* root){
    

    if(root==NULL){
        pair<Node<int>*,Node<int>*>p;
        //p.first=NULL;
        //p.second=NULL;
        return p;
    }
    pair <Node<int>*,Node<int>*> pL=help(root->left);
    pair <Node<int>*,Node<int>*> pR=help(root->right);
    
    Node<int>* temp=new Node<int>(root->data);
    
    if(pL.first==NULL && pL.second==NULL){
        pair <Node<int>*,Node<int>*> pan=make_pair(temp,temp);
        return pan;
    }
    else{
        pL.second->next=temp;
        temp->next=pR.first;
    }
    
    pair <Node<int>*,Node<int>*> pans;
    pans.first=pL.first;
    pans.second=pR.second;
    
    return pans;
    
}

Node<int>* constructBST(BinaryTreeNode<int>* root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    pair <Node<int>*,Node<int>*> p;
    
    p=help(root);
    
    return p.first;
    
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
    Node<int>* head = constructBST(root);
    while(head != NULL) {
        cout << head -> data << " ";
        head = head -> next;
    }
}