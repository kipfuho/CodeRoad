/*
Description
Given a sequence of integers a1, a2, ..., an. Compute the sum Q of elements of this sequence.
Input
Line 1: contains n (1 <= n <= 10000)
Line 2: contains a1, a2, ..., an (-10000 <= ai <= 10000)
Output
Write the value of Q
Example
Input
4
3 2 5 4
Output
14
*/
#include <bits/stdc++.h> 

using namespace std;

int main() 
{ 
    int sum = 0;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int temp; cin >> temp;
        sum += temp;
    }
    cout << sum;
}