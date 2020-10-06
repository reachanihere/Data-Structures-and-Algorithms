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
class ll{
    public:
    node* head;
    node* tail;
};

ll flatten(node* root)
{
    ll l;
    if(root==NULL)
    {
    l.head=l.tail=NULL;
    return l;
    }
    if(root->left==NULL && root->right==NULL)
    {
        l.head=l.tail=root;
        return l;
    }
    if(root->left!=NULL && root->right==NULL)
    {
        ll leftll = flatten(root->left);
        leftll.tail->right = root;
        l.head = leftll.head;
        l.tail=root;
        return l;

    }
    if(root->left==NULL && root->right!=NULL)
    {
        ll rightll = flatten(root->right);
        root->right = rightll.head;
        
        l.head=root;
        l.tail = rightll.tail;
        return l;

    }
    ll leftll = flatten(root->left);
    ll rightll = flatten(root->right);

    leftll.tail->right=root;
    root->right=rightll.head;

    l.head=leftll.head;
    l.tail=rightll.tail;
    return l;
}




int main()
{
    node* root = build();
    inorder(root);
    cout<<endl;
    bfs(root);

    ll l = flatten(root);
    node* temp = l.head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"-->";
        temp=temp->right;
    }
    cout<<"NULL"<<endl;



    return 0;

}

//23093 CB