#include<bits/stdc++.h>
using namespace std;



///for trees
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    node* left;
    node* right;
    int data;

    node(int d)
    {
        left=NULL;
        right=NULL;
        data=d;
    }
};

class pairr{
    public:
    int branchsum;
    int maxsum;

    pairr(){
        branchsum=0;
        maxsum=0;
    }
};

pairr MaxSumPath(node* root)
{
    pairr p;
    if(root==NULL)
    {
        return p;
    }
    pairr left = MaxSumPath(root->left);
    pairr right = MaxSumPath(root->right);

    //construct two values
    int op1 = root->data;
    int op2 = left.branchsum + root->data;
    int op3 = left.branchsum + right.branchsum + root->data;
    int op4 = right.branchsum + root->data;

    int curr_ans_through_root = max(op1,op2,op3,op4);

    //BRANCH SUM
    t.branchsum = (max(left.branchsum,right,branchsum,0))+root->data;

    p.maxsum = max(left.maxsum,right.maxsum,curr_ans_through_root);


}

node* buildtree(){
    int d;
    cin>>d;
    if(d==-1)
    {
        return NULL;
    }
    node* root = new node(d);
    root->left = buildtree();
    root->right=buildtree();

    return root;
}

int main()
{
    node* root=buildtree();
    
    return 0;
}