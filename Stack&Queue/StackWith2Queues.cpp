/*
You need to implement a Stack class using two queues as its data members.
Only 2 data members should be there inside the class - two queues, which should be created dynamically and both should be public. Use the inbuilt queue.
Implement the following public functions :
1. Constructor -
Initialises both the data members.
2. push :
This function should take one argument of type T and has return type void. This function should insert an element in the stack. Time complexity should be O(1).
3. pop :
This function takes no input arguments and has return type T. This should removes the last element which is entered and return that element as an answer.
4. top :
This function takes no input arguments and has return type T. This should return the last element which is entered and return that element as an answer.
5. getSize :
Return the size of stack i.e. count of elements which are present ins stack right now. Time complexity should be O(1).
 */


#include <queue>
using namespace std;

template <typename T>
class stack {
    // Complete this class
    public:
    queue<T> *q1;
    queue<T> *q2;
    
    stack(){
        q1=new queue<T>();
        q2=new queue<T>();
    }
    void push(T ele)
    {
        //If Stack is empty
        q1->push(ele);
        
    }
    T pop()
    {
        if (q1->size()==0)
            return 0;
        T ans;
        while(q1->size()>1){
            q2->push(q1->front());
            q1->pop();
        }
        ans=q1->front();
        q1->pop();
        while(!q2->empty())
        {
            q1->push(q2->front());
            q2->pop();
        }
        return ans;
    }
    T top()
    {
        if (q1->size()==0)
            return 0;
        T ans;
        while(q1->size()>1){
            q2->push(q1->front());
            q1->pop();
        }
        ans=q1->front();
        q2->push(q1->front());
        q1->pop();
        while(!q2->empty())
        {
            q1->push(q2->front());
            q2->pop();
        }
        return ans;
    }
    int getSize()
    {
        return q1->size()+q2->size();
    }
    
};

//Driver Code
#include <iostream>
int main(){
    stack<int> s;
    int choice, input;
    
    while(true){
        
        cin>>choice;
        
        switch(choice){
            case 1:
                cin >> input;
                s.push(input);
                break;
            case 2:
                cout << s.pop() << "\n";
                break;
            case 3:
                cout << s.top() << "\n";
                break;
            case 4 :
                cout << s.getSize() << endl;
                break;
            case 5 : // Test
                while(!s.q1 -> empty()) {
                    cout << s.q1 -> front() << " ";
                    s.q1 -> pop();
                }
                return 0;
            default:
                return 0;
                break;
        }
    }
}
