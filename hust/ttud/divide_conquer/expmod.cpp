/*
Description
Given two positive integers a and b. Compute a^b mod (10^9 + 7)
Input
One line contains two integers a and b (1 <= a,b <= 18446744073709551614)
Output
The value a^b mod (10^9+7)
Example
Input
2  3
Output
8
*/

#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ull unsigned long long
#define ll long long

using namespace std;

long long expmod(ull a, unsigned long long b, unsigned long long mod){
    if(a == 0) return 0;
    if(b == 0) return 1;
    if(b == 1) return a;
    if(a > mod) return expmod(a%mod, b, mod);
    unsigned long long temp = expmod(a, b/2, mod);
    if(b&1) temp = (temp*temp % mod)*a % mod;
    else temp = temp*temp % mod;
    return temp;
}

int main(){_
    unsigned long long a, b, mod = 1e9+7; cin >> a >> b;
    cout << expmod(a, b, mod);
    return 0;
}