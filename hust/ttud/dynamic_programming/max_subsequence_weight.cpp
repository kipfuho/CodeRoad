/*
Description
Given an integers sequence a=(a1, a2,…, an). A subsequence of aa is defined to be ai, ai+1,…, aj. 
The weight of a subsequence is the sum of its elements. Find the subsequence having the highest weight.
Input
Line 1 contains n (1≤n≤10^6)
Line 2 contains a_1,…,a_n (−500≤a_i≤500)
Output
Write the weight of the highest subsequence found.
Example
input
10
3 -1 -3 5 2 5 0 -1 5 4
output
20
*/

#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){_
    int n; cin >> n;
    int arr[n], dp[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    dp[0] = arr[0]; int max_weight = arr[0];
    for(int i = 1; i < n; i++){
        dp[i] = max(dp[i-1] + arr[i], arr[i]);
        if(dp[i] > max_weight) max_weight = dp[i];
    }
    cout << max_weight;
    return 0;
}