/*
Description
Given 2 positive integers n and M and n positive integers a1, a2, . . ., an. Compute the number 
Q of non-negative solutions to the following equation: a1*x1 + a2*x2 + . . . + an*xn = M

Input
Line 1: contains n and M (1 <= n <= 100, 1 <= M <= 10000)
Line 2: contains a1, a2, . . ., an (1 <= ai <= 10)

Output
Write Q mod 109+7

Example
Input 
3 4
2 3 2 

Output
3

Explanation: there are 3 solutions:
2*0 + 3*0 + 2*2 = 4
2*1 + 3*0 + 2*1 = 4
2*2 + 3*0 + 2*0 = 4
*/

#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ull unsigned long long
#define ll long long

using namespace std;

int arr[100], dp[100][10001];

int S(int k, int m){
    if(m == 0) return 1;
    if(k < 0) return 0;
    if(dp[k][m]) return dp[k][m];
    ll temp = 0;
    for(int i = 0; i <= m/arr[k]; i++){
        temp += S(k - 1, m - i*arr[k]);
    }
    dp[k][m] = temp;
    return temp;
}

int main(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << S(n - 1, m);
    return 0;
}