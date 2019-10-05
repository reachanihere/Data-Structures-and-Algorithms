/*
Sort a given linked list using Insertion Sort (iteratively).
You don't need to print the elements, just sort the elements and return the head of updated LL.

Input format : Linked list elements (separated by space and terminated by -1)`
Sample Input 1 :

1 4 5 2 -1

Sample Output 1 :

1 2 4 5


*/

// Following is the node structure
/**************
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
***************/


//insertion sort iterative
#include <iostream>
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

using namespace std;



void insert_sort(node* head,node* key){
    
    node* cur=head;
    while(cur->next){
        if(cur->next->data > key->data){
            key->next=cur->next;
            cur->next=key;
            return;
        }
        cur=cur->next;
    }
    cur->next=key;
}

node* insertion_sort_LinkedList_itr(node* head)
{
    //write your code here
    node* temphead=new node(0);
    temphead->next=head;
    
    node* cur=temphead;
    
    while(cur->next){
        node* temp=cur->next;
        if(cur->data>temp->data){
            cur->next=temp->next;
            temp->next=NULL;
            insert_sort(temphead,temp);
            continue;
        }
        cur=cur->next;
        
    }
    return temphead->next;
    
}

node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}
void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    node* head=takeinput();
    head=insertion_sort_LinkedList_itr(head);
    print(head);
}
