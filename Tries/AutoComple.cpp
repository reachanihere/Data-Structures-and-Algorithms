/*
Given n number of words and an incomplete word w. You need to auto-complete that word w.
That means, find and print all the possible words which can be formed using the incomplete word w.
Input Format :

Line 1 : Integer n
Line 2 : n words (separated by space)
Line 3 : Word w

Output Format :

All possible words (in different lines)

Note : Order of words doesn't matter.
Sample Input 1 :

7
do dont no not note notes den
no

Sample Output 2 :

no
not
note
notes

Sample Input 2 :

7
do dont no not note notes den
de

Sample Output 2 :

den

Sample Input 3 :

7
do dont no not note notes den
nom

Sample Output 3 :

(Empty) There is no word which starts with "nom"
 */




// #include "TrieNode.h"
#include <string>
#include <vector>
class TrieNode {
	public :
	char data;
	TrieNode **children;
	bool isTerminal;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
	}
};

class Trie {
	TrieNode *root;

	public :
	int count;

	Trie() {
		this->count = 0;
		root = new TrieNode('\0');
	}

	bool insertWord(TrieNode *root, string word) {
		// Base case
		if(word.size() == 0) {
			if (!root->isTerminal) {
				root -> isTerminal = true;
				return true;	
			} else {
				return false;
			}
		}

		// Small Calculation
		int index = word[0] - 'a';
		TrieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			child = new TrieNode(word[0]);
			root -> children[index] = child;
		}

		// Recursive call
		return insertWord(child, word.substr(1));
	}

	// For user
	void insertWord(string word) {
		if (insertWord(root, word)) {
			this->count++;
		}
	}
    
    void printWords(TrieNode *root,string word1)
    {
        if(root->isTerminal)
            cout<<word1<<endl;
        
        for(int i=0;i<26;i++)
        {
            if(root->children[i]!=NULL)
                printWords(root->children[i],word1+root->children[i]->data);
        }
    }
    
    bool search(TrieNode* root, string word,string word1){
        
        if(word.size()==0)
        {
            
            printWords(root,word1);
                
            return root->isTerminal;
        }
            
        int index =word[0]-'a';
        if(root->children[index]!=NULL)
            return search(root->children[index],word.substr(1),word1);
        else
            return false;
    }
    
    void autoComplete(vector<string> input, string pattern) {
        // Complete this function
        // Print the output as specified in question
        for(int i=0;i<input.size();i++)
            insertWord(input[i]);
        search(root,pattern,pattern);
        
    }

};



#include <iostream>
#include <string>
using namespace std;
#include <vector>


//Driver Code to test auto-completetion
int main() {
	Trie t;
    int N;
    cin >> N;
    string pattern;
    vector<string> vect;
    for (int i=0; i < N; i++) {
        string word;
        cin >> word;
        vect.push_back(word);
    }
    cin >> pattern;
    t.autoComplete(vect, pattern);
}

