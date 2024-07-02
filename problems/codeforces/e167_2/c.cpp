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

int mv1[200000], mv2[200000];

void sol(){
    int n; cin >> n;
    rep(i, n) cin >> mv1[i];
    rep(i, n) cin >> mv2[i];

    int r1 = 0, r2 = 0;
    vector<int> gr(2, 0);
    rep(i, n) {
        if(mv1[i] == -1 && mv2[i] == -1) {
            gr[0]++;
        }
        else if(mv1[i] == 1 && mv2[i] == 1) {
            gr[1]++;
        }
        else if(mv1[i] == 1) {
            r1++;
        }
        else if(mv2[i] == 1) {
            r2++;
        }
    }
    
    if(gr[0] > 0) {
        int dif = abs(r1 - r2);
        if(gr[0] > dif) {
            dif = gr[0] - dif;
            int newval = min(r1, r2) - dif/2;
            r1 = r2 = newval;
            if(dif&1) r1--;
        }
        else {
            if(r1 > r2) r1 -= gr[0];
            else r2 -= gr[0];
        }
    }
    if(gr[1] > 0) {
        int dif = abs(r1 - r2);
        if(gr[1] > dif) {
            dif = (gr[1] - dif)/2;
            int newval = max(r1, r2) + dif;
            r1 = r2 = newval;
        }
        else {
            if(r1 > r2) r2 += gr[1];
            else r1 += gr[1];
        }
    }
    cout << min(r1, r2) << '\n';
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