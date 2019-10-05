/*
A flag can consists of only three different colors of stripes, White(W), Blue(B) and Red(R). Given an integer N, find and return the number of ways to create such flags having N stripes consisting of these three color stripes only with the following constraints -

1. Stripes of the same color cannot be placed next to each other.
2. A blue stripe must always be placed between a white and a red or between a red and a white one. Hence blue stripe cannot be placed at starting or at ending.
3. Its not necessary to use all three colors.

Input Format :

Single Integer N

Output Format :

Single Integer representing number of ways to create a flag

Constraints :
1 <= N <= 30
Sample Input 1 :

3

Sample Output 1 :

4

Sample Output 1 Explanation :
Possible flags with 3 stripes are : WRW, WBR, RWR, RBW
Sample Input 2 :

4

Sample Output 2 :

6

Sample Output 2 Explanation :
Possible flags with 4 stripes are : WRWR, WRBW, WBRW, RWRW, RWBR, RBWR
*/


long long find_Ways(int N)
{
    /* Don't write main().
   * Don't read input, it is passed as function argument.
   * Taking input and printing output is handled automatically.
  */
    if(N==1 || N==2) return 2;
    
    long long ans=find_Ways(N-1)+find_Ways(N-2);
    
    return ans;
    

}

#include<iostream>
#include "solution.h"
using namespace std;

int main(){
int N;
cin>>N;
cout<<find_Ways(N);
}
