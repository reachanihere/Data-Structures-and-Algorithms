#include<bits/stdc++.h>
using namespace std;


class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;

    }
};

node* buildBST(node* root,int d)
{
    if(root==NULL)
    {
        node* val = new node(d);
        return val;
    }
    //REC insertions

    if(d<=root->data)
    {
        root->left = buildBST(root->left,d);
    }
    else
    {
        root->right =  buildBST(root->right,d);
    }
    return root;

}


node* build()
{
    int d;
    cin>>d;
    node* root=NULL;
    while(d!=-1)
    {
        root = buildBST(root,d);
        cin>>d;

    }
    return root;
}

void bfs(node* root)
{
    queue<node*> q;
    q.push(root);
    
    while(!q.empty())
    {
        int size = q.size();
        while(size--)
        {
            node* temp = q.front();
            cout<<temp->data<<" ";
            q.pop();

            if(temp->left)
            q.push(temp->left);

            if(temp->right)
            {
                q.push(temp->right);
            }
        }
        cout<<endl;
    }
    return ;

}

void inorder(node* root)
{
    if(root)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
    return;
}

node* deletenode(node* root,int d)
{
    if(root==NULL)
    return NULL;

    if(d<root->data)
    {
        root->left = deletenode(root->left,d);
        return root;

    }
    

    if(root->data==d)
    {
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            return NULL;
        }
        //2nd case
        if(root->left==NULL && root->right!=NULL)
        {
            node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->left!=NULL && root->right==NULL)
        {
            node* temp = root->left;
            delete root;
            return temp;
        }
        //finding inorder succesoorr
        node* replace = root->right;
        while (replace->left!=NULL)
        {
            replace=replace->left;
        }
        root->data = replace->data;
        root->right=deletenode(root->right,replace->data);
        return root;
        


    }
    else{
        root->right = deletenode(root->right,d);
        return root;
    }

}


int main()
{
    node* root = build();
    inorder(root);
    cout<<endl;
    bfs(root);

    root = deletenode(root,2);
    inorder(root);
    cout<<endl;
    bfs(root);




    return 0;

}