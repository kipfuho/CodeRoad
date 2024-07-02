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

int prefixSum[200001];

inline pii getPos(int i, int n, string &s, string &t) {
    if(s[i] == '1') return {i, i};
    int l = -1, r = -1;
    if(i > 0 && t[i - 1] == '1') {
        l = i - 1;
    }
    else if(i > 1 && s[i - 2] == '0') {
        l = i - 2;
    }

    if(i < n - 1 && t[i + 1] == '1') {
        r = i + 1;
    }
    else if(i < n - 2 && s[i + 2] == '0') {
        r = i + 2;
    }

    if(r == -1) l = -1;
    if(l == -1) r = -1;
    return {l, r};
}

void sol(){
    int n; cin >> n;
    string s, t; cin >> s >> t;
    prefixSum[0] = 0;
    rep(i, 1, n + 1) {
        pii pos = getPos(i - 1, n, s, t);
        prefixSum[i] = prefixSum[i - 1] + (pos.first != -1);
    }

    //rep(i, 1, n + 1) cout << prefixSum[i] << " \n"[i == n];

    int q; cin >> q;
    while(q--) {
        int l, r, cnt; cin >> l >> r;
        if(r - l < 5) {
            cnt = 0;
            rep(i, l, r + 1) {
                if(s[i - 1] == '1') cnt++;
                else {
                    pii pos = getPos(i - 1, n, s, t);
                    if(pos.first >= l - 1 && pos.second < r) cnt++;
                }
            }
        }
        else {
            cnt = prefixSum[r] - prefixSum[l - 1];
            for(int i : {l - 1, l, r - 2, r - 1}) {
                if(s[i] == '1') continue;
                pii pos = getPos(i, n, s, t);
                if(pos.first != -1 && (pos.first < l - 1 || pos.second >= r)) cnt--;
            }
        }
        cout << cnt << '\n';
    }
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