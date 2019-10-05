/*
Given a linked list, find and return the midpoint.
If the length of linked list is even, return the first mid point.

Input format : Linked list elements (separated by space and terminated by -1)`
Sample Input 1 :

1 2 3 4 5 -1

Sample Output 1 :

3

Sample Input 2 :

1 2 3 4 -1

Sample Output 2 :

2

*/

/***Note: the Fast/Slow pointer approach here *****/

//Find midpoint of a Linked List
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


node* midpoint_linkedlist(node *head)
{
    // Write your code here
    if(head==NULL)
        return NULL;
    if(head->next==NULL)
        return head;
    
    node* slow =head;
    node* fast=head->next;
    
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;

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
int main(){
    node*head=takeinput();
    node* mid=midpoint_linkedlist(head);
    cout<<mid->data;
    return 0;
}