/*
Given a binary tree, print that binary tree in vertical order. Vertical order is -

Print the nodes which are at same vertical order in same line separated by space. Print different levels in different lines.
Order of different levels in different lines is not important. But in one level, print the element in pre-order format.
Input Format :

Elements in level order form (separated by space). If any node does not have left or right child, take -1 in its place

Output Format :

Required output in given format

Sample Input :

1 2 3 4 5 6 7 -1 8 -1 -1 -1 -1 -1 -1 -1 -1

Sample Output :

7 
3 
4 
2 8 
1 5 6 

*/
#include <bits/stdc++.h>

void preOrd(BinaryTreeNode<int> *root,map<int,vector<int> >&m,int dis){
    
    if(root!=NULL){
        m[dis].push_back(root->data);
        preOrd(root->left,m,dis-1);
        preOrd(root->right,m,dis+1);
    }
}
	void printBinaryTreeVerticalOrder(BinaryTreeNode<int>* root) {	 
		
	// Following is the structure of the Binary Tree node class
	/*
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
	*/
	
	/* Don't write main().
     	* the root of the input binary tree is already passed as function argument.
     	* Taking input is handled automatically.
	* Print the binary tree in vertical order. Don't return anything.
     	*/
     	map<int,vector<int> > m;
        
        preOrd(root,m,0);
        
        map<int,vector<int> > :: iterator it;
        for(it=m.begin();it!=m.end();it++){
            vector<int> temp=it->second;
            
            for(int i=0;i<temp.size();i++)
                cout<<temp[i]<<" ";
            cout<<endl;
        }
        
     	
 	}



#include<iostream>
#include <queue>
#include<cmath>
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

#include "solution.h"


BinaryTreeNode<int>* takeInputLevelWise() {
    int data;
//  cout << "Enter root : ";
    cin >> data;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(data);

    queue<BinaryTreeNode<int>* > pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()) {
        BinaryTreeNode<int> *current = pendingNodes.front();
        pendingNodes.pop();

        int leftData, rightData;
    //  cout << "Enter left child of : " << current -> data << " : ";
        cin >> leftData;

        if(leftData != -1) {
            BinaryTreeNode<int> *left = new BinaryTreeNode<int>(leftData);
            current -> left = left;
            pendingNodes.push(left);
        }

    //  cout << "Enter right child of  " << current -> data << " : ";
        cin >> rightData;

        if(rightData != -1) {
            BinaryTreeNode<int> *right = new BinaryTreeNode<int>(rightData);
            current -> right = right;
            pendingNodes.push(right);
        }
    }
    return root;

}

int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printBinaryTreeVerticalOrder(root);
    return 0;
}
