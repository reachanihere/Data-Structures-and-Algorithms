#include <bits/stdc++.h> 
using namespace std;
void helperArray(char pattern[], int m, int lps[]) 
{ 
	int len = 0; 
	lps[0] = 0;
	int i = 1; 
	while (i < m) 
    { 
		if (pattern[i]==pattern[len]) 
        { 
			len++; 
			lps[i] = len; 
			i++; 
		} 
		else 
		{ 
			if (len != 0) 
            { 
				len = lps[len - 1]; 
			} 
			else 
			{ 
				lps[i] = 0; 
				i++; 
			} 
		} 
	} 
} 
void KMP(char pattern[], char text[]) 
{ 
	int m = strlen(pattern); 
	int n = strlen(text); 
	int pi[m]; 
	helperArray(pattern, m, pi); 
	int i = 0; 
	int j = 0; 
	while (i<n) 
    { 
		if (pattern[j]==text[i]) { 
			j++; 
			i++; 
            break;
		} 
		if (j==m) { 
			cout<<i-j<<endl;
            break;
		} 
		else if (i<n && pattern[j]!=text[i]) { 
			if (j != 0) 
				j = pi[j-1]; 
			else
				i=i+1; 
		} 
	} 
    for(int i=0;i<m;i++)
    cout<<pi[i]<<" ";
}


int main() 
{ 
	char text[1000]; 
	char pattern[1000];
    cin>>text>>pattern;
	KMP(pattern, text); 
	return 0; 
} 

//= "ABABDABACDABABCABAB"; 
// = "ABABCABAB"; 