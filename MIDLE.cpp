#include<bits/stdc++.h>
using namespace std;


int updated=0;

class node{
    public:
    node* next;
    int data;

    node(int d)
    {
        next=NULL;
        data=d;
    }
};
vector<node*> v;
map<int,int> mp;
node* insertAtEnd(node* head,int d)
{
    if(head==NULL)
    {
        node* newnode = new node(d);
        return newnode;
    }
    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    node* newnode = new node(d);
    temp->next=newnode;
    return head;
}

node* findAndInsert(node* head,int y,int x)
{
    node* temp1=head;
    node* prev=NULL;

    while(temp1->data!=y && temp1->data!=x && temp1!=NULL)
    {
        prev=temp1;
        temp1=temp1->next;
    }
    if(temp1->data==y)
    {
        node* newnode = new node(x);
        newnode->next = temp1->next;
        temp1->next=newnode;
    }
    else
    {
        node* newnode= new node(y);
        prev->next = newnode;
        newnode->next=temp1;    
    }

    return head;
}

node* insertAtMiddle(node* head,int z,int y,int x)
{
    node* temp=head;
    while(temp->data!=z)
    {
        temp=temp->next;
    }
    int len=0;
    node* agge = temp;
    while(agge->data!=y)
    {
        len++;
        agge=agge->next;
    }
    len=len/2;
    while(len--)
    {
        temp=temp->next;
    }

    node* newnode=new node(x);
    newnode->next=temp->next;
    temp->next=newnode;

    return head;
}


node* linkNext(node* head,int x,int p)
{
    node* temp1=head;
    node* temp = head;
    
    int len=0;
    while(temp1!=NULL)
    {
        len++;
        temp1=temp1->next;
    }
    int lenx=0;
    while(temp->data!=x)
    {
        temp=temp->next;
        lenx++;
    }
    if(lenx+p>len)
    {
        updated=1;
    }
    int final = (p%len)+lenx;
    node* target = head;

    while(final--)
    {
        target=target->next;
    }
    if(temp->next!=target)
    {
        v.push_back(temp->next);
    }
    temp->next=target;


    return head;
}


void print(node* head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    return;
}



int main()
{
    int t;
    cin>>t;
    node* head=NULL;
    while (t--)
    {

        char ch;

        cin>>ch;

        switch(ch)
        {
            case 'I':
            {
                int sr;
                cin>>sr;
                switch(sr)
                {
                    case 0:
                    {
                        int x;
                        cin>>x;
                        head = insertAtEnd(head,x);
                        break;

                    }
                    case 1:
                    {
                        int y,x;
                        cin>>y>>x;
                        head = findAndInsert(head,y,x);
                        break;

                    }
                    case 2:
                    {
                        int z,y,x;
                        cin>>z>>y>>x;
                        head = insertAtMiddle(head,z,y,x);
                        break;

                    }
                }
                break;
            }

            case 'U':
            {
                int x,p;
                cin>>x>>p;

                head =  linkNext(head,x,p);
                break;


            }
        }
        print(head);
        
    }
    cout<<updated<<endl;
    int cnt=0;
    for(int i=0;i<v.size();i++)
    {
        mp[v[i]->data]++;
        if(mp[v[i]->data]>1)
        {
            cnt++;
        }
    }
    cout<<cnt<<endl;


    
    
    return 0;
}

1 
1 7 
1 6 7 
1 2 6 7 
1 2 3 6 7 
1 2 3 5 6 7 
1 2 3 4 5 6 7 