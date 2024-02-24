// https://codeforces.com/contest/1891/problem/F

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

// fenwick tree query
int sz, idx;
ll nval[500005], l[500005], r[500005];
vector<array<int, 3>> query;
vector<int> child[500005];

// label range of child of node from l[node] to r[node]
void dfs(int node){
    l[node] = ++idx;
    for(auto ch:child[node]) dfs(ch);
    r[node] = idx;
    return;
}

// get sum from nval[1...x]
ll sum(int x){
    ll res = 0;
    for(int i = x; i > 0; i -= bit(i)) res += nval[i];
    return res;
}

// add x to nval[x....sz]
void update(int v, ll x){
    for(int i = v; i <= sz; i += bit(i)) nval[i] += x;
    return;
}

int main(){_
    int t; cin >> t;
    while(t--){
        int q; cin >> q;
        nval[1] = 0;
        sz = 1, idx = 0;
        int type, v, x;
        FOR(i, 1, q){
            cin >> type;
            if(type == 1){
                cin >> v;
                child[v].pb(++sz);
                query.pb({type, v, sz});
            }
            else if(type == 2){
                cin >> v >> x;
                query.pb({type, v, x});
            }
            else i--;
        }
        dfs(1);
        for(auto [type, v, x] : query){
            // type 1: get sum from father and grandfather of x as res, add -res to x and 
            // subtree of x, and add res to equalize others node which is not child of x
            // this way, if we get sum of l[x] we will get 0
            if(type == 1){
                ll res = sum(l[x]);
                update(l[x], -res), update(r[x] + 1, res);
            }
            // type 2: same energy as above, add x to subtree of v and add -x to equalize others node
            else{
                update(l[v], x), update(r[v] + 1, -x);
            }
        }
        FOR(i, 1, sz) cout << sum(l[i]) << " ";
        cout << endl;
        FOR(i, 1, sz){
            child[i].clear();
            nval[i] = l[i] = r[i] = 0;
        }
        query.clear();
    }
}