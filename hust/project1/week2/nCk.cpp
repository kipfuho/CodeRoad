/*
Given two positive integers k and n. Compute C(k,n) which is the number of ways to select k objects from a given set of n objects.
Input
Line 1: two positive integers k and n (1 <= k,n <= 999)
Output
Write te value C(k,n) modulo 10
9
+7.
Example
Input
3  5
Output
10
*/

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;
int fact[1001];

int multinv(int n, int m) {
    if (m == 1) return 0;
    int m0 = m, y = 0, x = 1, t;

    while (n > 1) {
        t = y;
        y = x - n/m*y;
        x = t;
        
        t = m;
        m = n%m;
        n = t;
    }
    
    return x<0 ? x+m0 : x;
}

int nCk(int n, int k, int m) {
    return (long long) fact[n]
         * multinv(fact[n-k], m) % m
         * multinv(fact[k], m) % m;
}

int main() {
    fact[0] = 1;
    for (int i = 1; i <= 1000; i++) {
        fact[i] = (long long) fact[i-1] * i % MOD;
    }

    int n, k; cin >> k >> n;
    cout << nCk(n, k, MOD);
}
