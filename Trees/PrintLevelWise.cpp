/*
Given a generic tree, print the input tree in level wise order. ####For printing a node with data N, you need to follow the exact format -

N:x1,x2,x3,...,xn

where N is data of any node present in the binary tree. x1, x2, x3, ...., xn are the children of node N
There is no space in between.
You need to print all nodes in the level order form in different lines.
Input format :

Elements in level order form separated by space (as per done in class). Order is - 
Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element 

Output Format :

Level wise print

Sample Input :

10 3 20 30 40 2 40 50 0 0 0 0 

Sample Output :

10:20,30,40
20:40,50
30:
40:
40:
50:
 */


#include <queue>
using namespace std;

#include <iostream>
#include <vector>

template <typename T>
class TreeNode {
public:
    T data;
    vector<TreeNode<T>*> children;
    
    TreeNode(T data) {
        this->data = data;
    }
    
    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
    
};



void printLevelWise(TreeNode<int>* root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output as specified in the question.
     */
    queue <TreeNode<int>*> pn;
    pn.push(root);
    
    while(!pn.empty()){
        TreeNode <int>* cur=pn.front();
        pn.pop();
        
        cout<<cur->data<<":";
        
        for(int i=0;i<cur->children.size();i++){
            if(i==cur->children.size()-1)
                cout<<cur->children[i]->data;
            else
                cout<<cur->children[i]->data<<",";
            pn.push(cur->children[i]);
        }
        cout<<endl;
    }
    
}

#include <queue>


TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    
    queue<TreeNode<int>*> pendingNodes;
    
    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
}
