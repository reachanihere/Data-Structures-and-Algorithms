
#include<iostream>

using namespace std;
/*Trick:- The numbers which are the powers of 2 , they have only one bit set in its binary form
ex:- 8 whose binary is 1000
and the number n(power of 2) has only one set bit, n-1 will have all the set bits after position
in the method below if the number is power of 2 then it have only one bit set , and the '&' of that number n and n-1 will leads to zero
and the outer && for the case when n is zero
*/

bool checkPowerOfTwo(int n){
    return !(n && (n & (n-1)));
}

int main(){
  cout<<checkPowerOfTwo(8);
  return 0;
}
