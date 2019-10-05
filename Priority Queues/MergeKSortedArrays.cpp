/*
Given k different arrays, which are sorted individually (in ascending order). You need to merge all the given arrays such that output array should be sorted (in ascending order).
Hint : Use Heaps.
Input Format :

Line 1 : Integer K
Line 2 : Arrays 1 size (n1)
Line 3 : Array 1 elements (separated by space)
Line 4 : Array 2 size (n2)
and so on for next arrays

Sample Input 1 :

4
3
1 5 9
2
45 90
5
2 6 78 100 234
1
0

Sample Output 1 :

0 1 2 5 6 9 45 78 90 100 234

 */



#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int> > pi; 

vector<int> mergeKSortedArrays(vector<vector<int>*> input){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return the output.
     * Taking input and printing output is handled automatically.
     */
    vector <int> ans;
    
    int maxsize=0;
    for(int i=0;i<input.size();i++){
        int x=input[i]->size();
        maxsize=max(maxsize,x);
    }
    
    priority_queue<pi,vector<pi>,greater< pi> > pq;
 
    
    for(int j=0;j<input.size();j++){
        vector <int>* v=input[j];
        pq.push(make_pair(v->at(0),make_pair(j,0)));
    }
    while(!pq.empty()){
        pair<int,pair<int,int> > p=pq.top();
        pq.pop();
        ans.push_back(p.first);
        
        int minIndexrow=p.second.first;
        int eleIndex=p.second.second;
        
        eleIndex++;
        vector <int>* v=input[minIndexrow];
        
        if(eleIndex<v->size())
            pq.push(make_pair(v->at(eleIndex),make_pair(minIndexrow,eleIndex)));
    }
                    
    return ans;
}


#include <iostream>
using namespace std;
#include <vector>

int main() {
	
	int k;
	cin >> k;
    vector<vector<int>*> input;
    for(int j = 1; j <= k; j++) {
        int size;
        cin >> size;
        vector<int> *current = new vector<int>;
        
        for(int i = 0; i < size; i++) {
            int a;
            cin >> a;
            current -> push_back(a);
        }
        input.push_back(current);
    }
	
	
	vector<int> output = mergeKSortedArrays(input);

	for(int i = 0; i < output.size(); i++)
		cout << output[i] << " ";
	
	return 0;
}
