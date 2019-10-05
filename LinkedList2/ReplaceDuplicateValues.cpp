/*
Given a linked list that contain some random integers from 1 to n with many duplicates. You need to replace each duplicate element that is present in the linked list with the values n+1, n+2, and so on (starting from left to right in given LL).
For eg. if input linked list is

1 3 1 4 4 2 1 -1

updated linked list should be -

1 3 5 4 6 2 7

n in the list is 4, so I have to replace each duplicate from left to right with 4, 5 and so on. In that way, element 1 (which is at index 2) will be replaced by 5, element 4 (which is present at index 4) by 6 and element 1 (which is present at index 6) by 7.
You don't need to print the elements, just update the elements in LL.
Input format :

Linked list elements (separated by space and terminated by-1)

Output Format :

Updated LL elements (separated by space)

Sample Input 1 :

1 3 1 4 4 2 1 -1

Sample Output 1 :

1 3 5 4 6 2 7

 */



#include <bits/stdc++.h>
using namespace std;

#include <iostream>
template <typename T>
class Node{
public:
    T data;
    Node<T> * next;
    Node(T data){
        this->data=data;
        this->next=NULL;
    }
};
using namespace std;


int getN(Node<int>* head){
    Node<int>* cur=head;
    
    int n=0;
    while(cur!=NULL){
        n=max(n,cur->data);
        cur=cur->next;
    }
    return n;
}

void changeLL(Node<int>* head) {
    //write your code here
    unordered_map <int,int> m;
    
    int n=getN(head);
    
    Node<int>* cur=head;
    while(cur!=NULL)
    {
        if(m.count(cur->data)==0)
            m[cur->data]=1;
        else
        {
            n++;
            cur->data=n;
        }
        cur=cur->next;
    }
}

Node<int>* takeinput(){
    int data;
    cin>>data;
    Node<int>* head=NULL,*tail=NULL;
    while(data!=-1){
        Node<int> *newNode=new Node<int>(data);
        if(head==NULL)                  {
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
        cin>>data;
    }
    return head;
}
void print(Node<int> *head)
{
    Node<int> *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    Node<int>* head =takeinput();
    changeLL(head);
    print(head);
    return 0;
}
