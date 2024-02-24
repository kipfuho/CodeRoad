// https://codeforces.com/contest/1900/problem/D

#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define FOD(i, r, l) for(int i = r; i >= l; i--)
#define ull unsigned long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define YES cout << "YES\n";
#define NO cout << "NO\n";
#define Yes cout << "Yes\n";
#define No cout << "No\n";
#define bit(x) (x & (-x))

using namespace std;

int arr[80001];

inline int gcd(int a, int b){
    if(b%a == 0) return a;
    return gcd(b%a, a);
}

void sol(){
    int n; cin >> n;
    ll res = 0;
    FOR(i, 1, n) cin >> arr[i];
    sort(arr + 1, arr + 1 + n);
    FOR(i, 1, n - 2){
        FOR(j, i + 1, n - 1){
            res += gcd(arr[i], arr[j])*(n - j);
        }
    }
    cout << res << endl; 
    return;
}

int main(){_
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t; cin >> t;
    while(t--){
        sol();
    }
    return 0;
}