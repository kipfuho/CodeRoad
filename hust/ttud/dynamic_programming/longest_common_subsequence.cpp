/*
Description
Denote X = X1, X2, …, Xn, a subsequence of X is created by removing some element from X.  Given two 
sequences X = X1, X2, …, Xn and Y = Y1, Y2, …, Ym.
Find a common subsequence of X and Y such that the length is the longest.
Input
Line 1: two positive integers n and m (1 <= n,m <= 10000)
Line 2: n integers X
1, X2, …, Xn
Line 3:  m integers Y1, Y2, …, Ym
Output
Length of the longest subsequence of X and Y
Example 
Input
7 10
3 7 2 5 1 4 9
4 3 2 3 6 1 5 4 9 7
Output
5
*/

#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ull unsigned long long
#define ll long long

using namespace std;

int arr1[10001], arr2[10001], dp[10001][10001];
char trace[10001][10001];

int main(){_
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> arr1[i];
    for(int i = 1; i <= m; i++) cin >> arr2[i];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(arr1[i] == arr2[j]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
                trace[i][j] = 'd';
            }
            else{
                if(dp[i][j - 1] > dp[i - 1][j]){
                    dp[i][j] = dp[i][j - 1];
                    trace[i][j] = 'u';
                }
                else{
                    dp[i][j] = dp[i - 1][j];
                    trace[i][j] = 'l';
                }
            }
        }
    }
    cout << dp[n][m] << endl;
    int i = n, j = m;
    while(i > 0 && j > 0){
        if(trace[i][j] == 'd'){
            cout << arr1[i] << " ";
            i--; j--;
        }
        else if(trace[i][j] == 'u'){
            j--;
        }
        else{
            i--;
        }
    }
    return 0;
}