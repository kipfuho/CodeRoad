//

#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rep1(a) for (int i = 0; i < (a); i++)
#define rep2(i, a) for (int i = 0; i < (a); i++)
#define rep3(i, a, b) for (int i = a; i < (b); i++)
#define rep4(i, a, b, c) for (int i = a; i < (b); i += (c))
#define overload4(a, b, c, d, e, ...) e
#define rep(args...) overload4(args, rep4, rep3, rep2, rep1)(args)
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

// safe hash function for unordered_map and gp_hash_table
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

// fenwick tree
struct ftree{
    int n;
    vector<int> arr;

    ftree(int size) {
        n = size + 1;
        arr.resize(n + 1, 0);
    }

    void reset() {
        fill(arr.begin(), arr.end(), 0);
    }

    void update(int x, int val) {
        x++; // move to 1-indexed
        while(x <= n){
            arr[x] += val;
            x += bit(x);
        }
    }

    // prefix sum up to r
    ll prefix_sum(int r) {
        ll res = 0;
        while(r > 0) {
            res += (ll)arr[r];
            r -= bit(r);
        }
        return res;
    }

    // sum from l to r - 1
    ll get_sum(int l, int r) {
        if(l > 0) {
            return prefix_sum(r) - prefix_sum(l);
        } else {
            return prefix_sum(r);
        }
    }
};

int mat1[500][500], mat2[500][500];

void sol(){
    int n, m; cin >> n >> m;
    rep(i, n) {
        string temp; cin >> temp;
        rep(j, m) mat1[i][j] = temp[j] - '0';
    }
    rep(i, n) {
        string temp; cin >> temp;
        rep(j, m) {
            mat2[i][j] = temp[j] - '0';
        }
    }
    int sum1 = 0, sum2 = 0;
    vector<int> row1(n), row2(n), col1(m), col2(m);
    rep(i, n) rep(j, m) {
        sum1 += mat1[i][j];
        row1[i] += mat1[i][j];
        col1[j] += mat1[i][j];
    }
    rep(i, n) rep(j, m) {
        sum2 += mat2[i][j];
        row2[i] += mat2[i][j];
        col2[j] += mat2[i][j];
    }
    for(int &num : row1) num%=3;
    for(int &num : col1) num%=3;
    for(int &num : row2) num%=3;
    for(int &num : col2) num%=3;
    if(abs(sum1 - sum2)%3 != 0) {
        No
        return;
    }
    rep(i, n) if(row1[i] != row2[i]) {
        No
        return;
    }
    rep(i, m) if(col1[i] != col2[i]) {
        No
        return;
    }
    Yes;
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