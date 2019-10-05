#include <vector>
using namespace std;
//This Min-Prioity Queue. Max one could be implemented with reversing of inequalities in up and donw heapify process
class PriorityQueue {
    vector<int> pq; //We use the idea of array representing complete binary trees
    //So if ith node is root then 2i+1 and 2i+2 node are it s left and right child respectively
    
    public :
    
    PriorityQueue() {
        
    }
    
    bool isEmpty() {
        return pq.size() == 0;
    }
    
    // Return the size of priorityQueue - no of elements present
    int getSize() {
        return pq.size();
    }
    
    int getMin() {
        if(isEmpty()) {
            return 0;		// Priority Queue is empty
        }
        return pq[0];
    }
    
    void insert(int element) {
        pq.push_back(element);
        
        int childIndex = pq.size() - 1;
        
        //UP-HEAPIFY
        while(childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;
            
            if(pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else {
                break;
            }
            childIndex = parentIndex;
        }
        
    }
    
    int removeMin() {
        // Complete this function
        int rmin=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();
        
        int pIndex=0;
        int lchild=1;
        int rchild=2;
        
        //DOWN-HEAPIFY
        while(rchild<pq.size()){
            int minIndex=pIndex;
            int minchild=min(pq[lchild],pq[rchild]);
            
            if(minchild==pq[lchild] && minchild<pq[pIndex]){
                minIndex=lchild;
            }
            else if(minchild==pq[rchild] && minchild<pq[pIndex]){
                minIndex=rchild;
            }
            
            if(minIndex==pIndex)
                break;
            else{
                int temp=pq[minIndex];
                pq[minIndex]=pq[pIndex];
                pq[pIndex]=temp;
                
                pIndex=minIndex;
                lchild=2*pIndex+1;
                rchild=2*pIndex+2;
            }
        }
        
        return rmin;
        
    }
    
    
};


//Driver code to test PriorityQueue Class
#include <iostream>
using namespace std;
#include <climits>

int main() {
    PriorityQueue pq;
    int choice;
    cin >> choice;
    while(choice != -1) {
        switch(choice) {
            case 1 : // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2 : // getMin
                cout << pq.getMin() << endl;
                break;
            case 3 : // removeMax
                cout << pq.removeMin() << endl;
                break;
            case 4 : // size
                cout << pq.getSize() << endl;
                break;
            case 5 : // isEmpty
                if(pq.isEmpty()) {
                    cout << "true" << endl;
                }
                else {
                    cout << "false" << endl;
                }
            default :
                return 0;
        }
        cin >> choice;
    }
}
