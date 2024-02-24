/*
Description
Given a sequence a of positive a1, a2, . . ., an. A subsequence of a is defined to be the sequence obtained by removing some elements.
Find the subsequence of a such that the elements is in an increasing order and the number of elements of the subsequence is maximal.

Input
Line 1: contains a positive integer n (1 <= n <= 10000)
Line 2: contains n elements of the given sequence (1 <= ai <= 10000)
Output
The length of the subsequence found.

Example
Input 
6
5 8 2 8 10 10 

Output
3
*/

#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ull unsigned long long
#define ll long long

using namespace std;

int main(){_
    int n; cin >> n;
    vector<int> arr(n), dp(n, 1);
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    int max_len = 1;
    for(int i = 1; i < n; i++) max_len = max(max_len, dp[i]);
    cout << max_len;
    return 0;
}