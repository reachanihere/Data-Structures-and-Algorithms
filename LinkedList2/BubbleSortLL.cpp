/*
Sort a given linked list using Bubble Sort (iteratively). While sorting, you need to swap the entire nodes, not just the data.
You don't need to print the elements, just sort the elements and return the head of updated LL.

Input format : Linked list elements (separated by space and terminated by -1)`
Sample Input 1 :

1 4 5 2 -1

Sample Output 1 :

1 2 4 5


*/

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


node* bubble_sort_LinkedList_itr(node* head)
{
    //write your code here
    node * i=head;
    
    while(i){
        node *j=head;
        node *prev=head;
        while(j->next){
            node* temp=j->next;
            if(j->data>temp->data){
                if(j==head){
                    j->next=temp->next;
                    temp->next=j;
                    prev=temp;
                    head=prev;
                }
                else{
                    j->next=temp->next;
                    temp->next=j;
                    prev->next=temp;
                    prev=temp;
                }
                continue;
            }
            prev=j;
            j=j->next;
            
        }
        i=i->next;
    }
    return head;
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
    head=bubble_sort_LinkedList_itr(head);
    print(head);
}

