/*
Sort a given linked list using Merge Sort.
You don't need to print the elements, just sort the elements and return the head of updated LL.
Input format :

Linked list elements (separated by space and terminated by -1)

Output format :

Updated LL elements (separated by space)

Constraints :
1 <= Length of LL <= 1000
Sample Input 1 :

1 4 5 2 -1

Sample Output 1 :

1 2 4 5


*/

#include "Merge2SortedList.cpp"
#include "MidPointofLL.cpp"

//merge sort recursive
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




node* mergeSort(node *head) {
    //write your code here
    if(head->next!=NULL){
        node* mid=midpoint(head);
        node* mid_1=mid->next;
        mid->next=NULL;
        
        node* left=mergeSort(head);
        node* right=mergeSort(mid_1);
        
        node* ans=merge(left,right);
        return ans;
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
    head= mergeSort(head);
    print(head);
    return 0;
}
