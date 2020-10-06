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
bool searchInBST(node* root,int d)
{
    if(root==NULL)
    return false;

    if(root->data==d)
    return true;

    if(root->data>d)
    return searchInBST(root->left,d);
    else
    {
        return searchInBST(root->right,d);
    }
}



int main()
{
    node* root = build();
    inorder(root);
    cout<<endl;
    bfs(root);
    bool ans = searchInBST(root,6);
    if(ans)
    cout<<"UES"<<endl;
    else
    {
        cout<<"NO"<<endl;
    }
    



    return 0;

}