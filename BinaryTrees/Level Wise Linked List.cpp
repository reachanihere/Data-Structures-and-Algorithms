/*
Given a binary tree, write code to create a separate linked list for each level. You need to return the array which contains head of each level linked list.
Input format :

Elements in level order form (separated by space). If any node does not have left or right child, take -1 in its place.

Output format : Each level linked list is printed in new line (elements separated by space).

Sample Input :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output :
5 
6 10 
2 3 
9

=====Scratch
   5
  / \
  6 ->10
 / \  \
 2 ->3->  9
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class node{
public:
    T data;
    node<T> * next;
    node(T data){
        this->data=data;
        this->next=NULL;
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

// Following is the Node and Binary Tree node structure

/**************
class node{
public:
    T data;
    node<T> * next;
    node(T data){
        this->data=data;
        this->next=NULL;
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

vector<node<int>*> createLLForEachLevel(BinaryTreeNode<int> *root) {
    // Write your code here
    queue <BinaryTreeNode<int>* > q;
    q.push(root);
    q.push(NULL); //Make a note of, a very useful approach in seggrating levels in binary tree
    
    vector <node<int>*> heads;
    node<int>* fhead=NULL;
    node<int>* ftail=NULL;
    while(!q.empty()){
        
        BinaryTreeNode<int>* curr=q.front();
        q.pop();
        
        if(curr==NULL)
            break;
        if(fhead==NULL && ftail==NULL){
            node <int>* temp=new node<int>(curr->data);
            fhead=temp;
            ftail=temp;
        }
        else{
            node <int>* temp=new node<int>(curr->data);
            ftail->next=temp;
            ftail=temp;
        }
        if(curr->left){
            q.push(curr->left);
        }
        if(curr->right){
            q.push(curr->right);
        }
        
        if(q.front()==NULL){
            heads.push_back(fhead);
            q.pop();
            q.push(NULL);
            fhead=NULL;
            ftail=NULL;
        }
    }
    
    return heads;
       
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

void print(node<int> *head)
{
    node<int> *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    vector<node<int>*> ans = createLLForEachLevel(root);
    for(int i = 0; i < ans.size(); i++) {
	    print(ans[i]);
    }
}


