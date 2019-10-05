/*
A rooted binary tree is called “nice”, if every node is either a leaf, or has exactly two children.
For example, the following tree is nice,
                           n
                         /   \
                        l     n
                             / \
                            n   l
                           / \
                          l   l
and the following tree is not,
                          n
                         / \
                       n     n
                      /
                     l
The leaves of a nice binary tree are labeled by the letter ‘l’, and other nodes are labeled by the letter ‘n’.
Given the pre-order traversal of a nice binary tree as a string, you are required to find the depth of the tree.
Output one line for each test case, containing a single integer, the depth of tree.
Sample Input 1:
                nlnll
Sample Output 1:
                2
Sample Input 2:
                nll
Sample Output 2:
                1
*/


#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;


int depth(char str[]) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    if(str[0]=='l')
        return 1;
    
    int dep=0;
    if(str[1]=='n' && str[2]=='n')
        dep=1+max(depth(str+1),depth(str+2));
    
    else if(str[1]=='n')
        dep=1+depth(str+1);
    else if(str[2]=='n')
        dep=1+depth(str+2);
    else
        dep=depth(str+1);
    
    return dep;
}


int main()
{
	char *str = new char[100000];
	cin>>str;
	cout<<depth(str);
	return 0;
}


