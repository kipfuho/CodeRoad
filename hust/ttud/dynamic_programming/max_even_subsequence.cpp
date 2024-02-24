/*
Description
Given a sequence of n integers a=a1, . . ., an. A subsequence of a consists of contiguous 
elements of a (for example, ai, ai+1, . . . ,aj). The weight of a subsequence is defined to 
be the sum of its elements. A subsequence is called even-subsequnce if its weight is even. 
Find the even-subsequence of a having largest weight.
Input
Line 1: contains a positive integer n (1 <= n <= 10^6)
Line 2: contains a1, . . ., an (-10^6 <= ai <= 10^6)
Output
The weight of the largest even-subsequence found, or write NOT_FOUND if no solution found.
Example
Input
4
1  2  -3  4
Output
4
*/

#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ull unsigned long long
#define ll long long

using namespace std;

ll arr[1000000], dp1[1000000], dp2[1000000];

int main(){_
    //freopen("text.txt", "r", stdin);
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    dp1[0] = (arr[0]%2 == 1) ? arr[0] : 0;
    dp2[0] = (arr[0]%2 == 0) ? arr[0] : 0;
    ll max_even_weight = dp2[0];

    for(int i = 1; i < n; i++){
        if(arr[i]&1){
            dp1[i] = max(dp2[i-1] + arr[i], arr[i]);
            dp2[i] = dp1[i-1] + arr[i];
        }
        else{
            dp2[i] = max(dp2[i-1] + arr[i], arr[i]);
            dp1[i] = dp1[i-1] + arr[i];
        }
        max_even_weight = max(max_even_weight, dp2[i]);
    }

    cout << max_even_weight;
    return 0;
}