/*
Description
Given a sequence of integers a1, a2, ..., an. A pair (i, j) is call an inversion if i < j and ai > aj. 
Compute the number Q of inversions
Input
Line 1: contains a positive integer n (1 <= n <= 10^6)
Line 2: contains a1, a2, ..., an (0 <= ai<= 10^6)
Output
Write the value Q modulo 10^9+7
Example
Input
6
3 2 4 5 6 1
Output
6
*/

#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){_
    int n; cin >> n;
    vector<int> bit(1000001, 0), arr(n);
    auto update = [&](int x){
        while(x < 1000001){
            bit[x]++;
            x += (x&(-x));
        }
        return 0;
    };
    auto get = [&](int x){
        int sum = 0;
        while(x > 0){
            sum += bit[x];
            x -= (x&(-x));
        }
        return sum;
    };
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    long long total = 0;
    int mod = 1e9 + 7;
    for(int i = n - 1; i >= 0; i--){
        total = (total + get(arr[i]))%mod;
        update(arr[i] + 1);
    }
    cout << total;
    return 0;
}