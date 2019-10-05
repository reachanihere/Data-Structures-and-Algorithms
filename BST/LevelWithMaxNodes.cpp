/*
Given a generic tree, return the level number, which is having maximum number of nodes(root is level 0).
Note : If there are multiple levels having maximum number of nodes, print the level which comes first.
Input format :

Line 1 : Elements will be input in level order form separated by space. Order is - 
Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element. 

Output format

Line 1 : Level with maximum nodes

Sample Input 1 :

2 2 1 3 2 4 6 1 8 0 1 5 0 0

Sample Output 1 :

2

Sample Output Explanation

Level 2 has maximum number of nodes i.e. 3 nodes (Nodes 4,6 and 8 are at level 2)

 */


/* Following is the given Tree node structure
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
#include <bits/stdc++.h>
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

int maxLevel(TreeNode<int> *root){
    
	/* Don't write main().
	   Don't read input, it is passed as function argument.
	   Return output and don't print it.
	   Taking input and printing output is handled automatically.
	*/
    vector <int> temp;
    
    queue<TreeNode<int>* > q;
    q.push(root);
    q.push(NULL);
    
    int width=0;
    int curlevel=0;
    int level=0;
    while(!q.empty()){
        TreeNode<int>* cur=q.front();
        q.pop();
        if(cur==NULL)
            break;
        temp.push_back(cur->data);
        for(int i=0;i<cur->numChildren();i++){
            q.push(cur->getChild(i));
        }
        if(q.front()==NULL){
            int t=temp.size();
            if(width<t){
                level=curlevel;
                width=t;
            }
            temp.clear();
            q.pop();
            q.push(NULL);
            curlevel++;
        }
    }
    return level;
}





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

#include <iostream>
using namespace std;

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

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    cout << maxLevel(root) << endl;
}
