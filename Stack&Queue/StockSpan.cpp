/*
he span si of a stock’s price on a certain day i is the minimum number of consecutive days (up to the current day) the price of the stock has been less than its price on that ith day. If for a particular day, if no stock price is greater then just count the number of days till 0th day including current day.
For eg. if given price array is {3, 6, 8, 1, 2}, span for 4th day (which has price 2) is 2 because minimum count of consecutive days (including 4th day itself) from current day which has price less than 4th day is 2 (i.e. day 3 & 4). Similarly, span for 2nd day is 3 because no stock price in left is greater than 2nd day's price. So count is 3 till 0th day.
Given an input array with all stock prices, you need to return the array with corresponding spans of each day.
Note : Try doing it in O(n).
Input format :

Line 1 : Integer n, Arrays Size
Line 2 : Price for n days (separated by space). It can contain duplicate values`

Output format :

Return an array that contain span for each day

Sample Input 1 :

8
60 70 80 100 90 75 80 120

Sample Output 1 :

1 2 3 4 1 1 2 8

Sample Input 2 :

 4
 1 1 1 1

Sample Output 2 :

1 1 1 1

 */

#include <stack>
#include <iostream>
#include <vector>
using namespace std;
int* stockSpan(int *price, int size) {
	// Write your code here
    int *si=new int[size];
    
    stack<int> s;
    si[0]=1;
    s.push(price[0]);
    for(int i=1;i<size;i++){
        if(price[i]>s.top()){
            int c=1;
            vector <int> v;
            while(!s.empty() && price[i]>s.top()){
                c++;
                v.push_back(s.top());
                s.pop();
            }
            si[i]=c;
            for(int j=v.size()-1;j>=0;j--)
                s.push(v[j]);
            s.push(price[i]);
        }
        else{
            si[i]=1;
            s.push(price[i]);
        }
    }
    return si;
    

}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];
    for(int i = 0; i < size; i++) {
    	cin >> input[i];
    }
    int *output = stockSpan(input, size);
    for(int i = 0; i < size; i++) {
    	cout << output[i] << " ";
    }
}
