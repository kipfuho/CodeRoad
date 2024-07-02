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

void sol(){
    string s; cin >> s;
    int chr[26] = {0};
    for(char c : s) chr[c - 'a']++;
    string half = "";
    rep(i, 26) {
        while(chr[i] > 1) {
            half += string(1, static_cast<char>('a' + i));
            chr[i] -= 2;
        }
    }
    if(half.size() > 0) {
        int idx = -1;
        rep(i, 26) {
            if(chr[i]) {
                idx = i;
                if(i > half[0] - 'a') break;
            }
        }
        rep(i, idx) {
            if(chr[i]) cout << static_cast<char>('a' + i);
        }
        cout << half;
        if(idx != -1) cout << static_cast<char>('a' + idx);
        reverse(half.begin(), half.end());
        cout << half;
        rep(i, idx + 1, 26) {
            if(chr[i]) cout << static_cast<char>('a' + i);
        }
    }
    else {
        rep(i, 26) {
            rep(j, chr[i]) cout << static_cast<char>('a' + i);
        }
    }
    return;
}

int main(){_
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    sol();
    return 0;
}