/*
Given a generic tree, find and return the node with second largest value in given tree. Return NULL if no node with required value is present.
Input format :

Line 1 : Elements in level order form separated by space (as per done in class). Order is -

Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element

Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 :
40

Failing test case
*/

// Following is the given Tree node structure
/**************

class TreeNode {
	TreeNode<T>** children;
	int childCount;

	public:
	T data;

	TreeNode(T data);	// Constructor
	int numChildren();
	void addChild(TreeNode<T>* child);
	TreeNode<T>* getChild(int index);
	void setChild(int index, TreeNode<T>* child);
};

***************/

#include <iostream>
#include <climits>
using namespace std;

template <typename T>
class TreeNode {
	TreeNode<T>** children;
	int childCount;
    	int maxChildCount;
	public:
		T data;

		TreeNode(T data) {
			this->data = data;
			childCount = 0;
			children = new TreeNode<T>*[10];
		   	maxChildCount = 10;
        }

		int numChildren() {
			return childCount;
		}

		void addChild(TreeNode<T>* child) {
			children[childCount] = child;
			childCount++;
            if(childCount == maxChildCount) {
	            TreeNode<T>** childrenNew = new TreeNode<T>*[2*maxChildCount];
        	    for(int i = 0; i < maxChildCount; i++) {
	                childrenNew[i] = children[i];
        	     }
	        	 maxChildCount *= 2;
        	        children = childrenNew;
	        }
		}

		TreeNode<T>* getChild(int index) {
			return children[index];
		}

		void setChild(int index, TreeNode<T>* child) {
			children[index] = child;
		}
};

template <typename T>
class Queue {
	T* data;
	int capacity;
	int nextIndex;
	int firstIndex;
	int length;

	public:
		Queue() {
			capacity = 10;
			data = new T[capacity];
			length = 0;
			nextIndex = 0;
			firstIndex = -1;
		}

		int size() {
			return length;
		}

		bool isEmpty() {
			return length == 0;
		}

		T front() {
			if (length == 0) {
				return 0;
			}
			return data[firstIndex];
		}

		T dequeue() {
			if (length == 0) {
				return 0;
			}

			T output = data[firstIndex];
			length--;
			firstIndex = (firstIndex + 1)%capacity;
			if (length == 0) {
				firstIndex = -1;
				nextIndex = 0;
			}
			return output;
		}

		void enqueue(T element) {
			if (length == capacity) {
				T* temp = data;
				capacity = 2* capacity;
				data = new T[capacity];
				int k = 0;
				for (int i = firstIndex; i < length; i++) {
					data[k] = temp[i];
					k++;
				}
				for (int i = 0; i < firstIndex; i++) {
					data[k] = temp[i];
					k++;
				}
				delete [] temp;
				firstIndex = 0;
				nextIndex = length;
			}
			data[nextIndex] = element;
			length++;
			nextIndex = (nextIndex + 1) % capacity;
			if (firstIndex == -1) {
				firstIndex = 0;
			}
		}

		~Queue() {
			delete [] data;
		}


};



TreeNode<int>* takeInputLevelWise() {
	Queue<TreeNode<int>*> q;
	int rootData;
	
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);
	q.enqueue(root);
	while (!q.isEmpty()) {
		TreeNode<int>* frontNode = q.dequeue();

		int numChildren;
		cin >> numChildren;
		for (int i = 0; i < numChildren; i++) {

			int childData;
			cin >> childData;
			TreeNode<int>* childNode = new TreeNode<int>(childData);
			q.enqueue(childNode);
			frontNode->addChild(childNode);
		}
	}
	return root;
}

class Pair{
    
    public:
    TreeNode<int>* maxcurr;
    TreeNode<int>* smaxcurr;

};

Pair help(TreeNode<int>* root){
    
    if(root==NULL){
        Pair p;
        p.maxcurr=NULL;
        p.smaxcurr=NULL;
        return p;
    }
    if(root->numChildren()==0){
        Pair p;
        p.maxcurr=root;
        p.smaxcurr=NULL;
        return p;
        
    }
    
    TreeNode <int>* maxcurr=root;
    TreeNode <int>* smaxcurr=NULL;
    
    for(int i=0;i<root->numChildren();i++){
        
        Pair ans=help(root->getChild(i));
        //Will have to work out many cases for maxcurrent and second maxcurrent
        if(maxcurr->data >ans.maxcurr->data){
            if(smaxcurr==NULL)
                smaxcurr=ans.maxcurr;
            else if(smaxcurr->data<ans.maxcurr->data)
                smaxcurr=ans.maxcurr;
        }
        else{
            TreeNode<int>* x=maxcurr;
            maxcurr=ans.maxcurr;
            if(ans.smaxcurr==NULL)
                smaxcurr=x;
            else if (x->data>ans.smaxcurr->data)
                smaxcurr=x;
            else
                smaxcurr=ans.smaxcurr;
        }
    }
    Pair p;
    p.maxcurr=maxcurr;
    p.smaxcurr=smaxcurr;
    return p;
}

TreeNode <int>* secondLargest(TreeNode<int> *root) {
    // Write your code here
    Pair p=help(root);
    
    return p.smaxcurr;

}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* ans = secondLargest(root);
    if(ans == NULL)
    	cout << INT_MIN << endl;
    else
	cout << ans -> data << endl;
}
