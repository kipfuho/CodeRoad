#include <iostream>
using namespace std;

const int MAXN = 1000; // Increase if necessary
const int MOD = 1e9+7; // A common mod that's used, change if necessary

int fact[MAXN+1];

int multinv(int n, int m) {
    /* Multiplicative inverse of n mod m in log(m) */
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

int choose(int n, int k, int m) {
    return (long long) fact[n]
         * multinv(fact[n-k], m) % m
         * multinv(fact[k], m) % m;
}

int main() {
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        fact[i] = (long long) fact[i-1] * i % MOD;
    }

    cout << choose(1e6, 1e3, MOD) << '\n';
}
