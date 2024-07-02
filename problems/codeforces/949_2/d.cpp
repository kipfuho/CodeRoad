// https://codeforces.com/contest/1981/problem/D

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

int MAX_P = 3e5;
int MAXN = 1e6;
int prime[20000], arr[20000];
bool vis[MAXN];
vector<pii> graph[20000];

// find prime numbers
void init() {
    for(i, 0, MAXN + 1) vis[i] = 0;

    int idx = 0;
    rep(i, 2, MAX_P + 1) {
        if(!vis[i]) prime[idx++] = i;
        int temp = i;
        while(temp <= MAX_P) {
            vis[temp] = 1;
            temp *= i;
        }
    }

    return;
}

void dfs(int u, int& idx) {
    for(pii v: graph[u]) {
        if(vis[v.second]) continue;

        vis[v.second] = 1;
        dfs(v);
    }

    arr[--idx] = prime[idx];
    return;
}

bool check(int x, int n) {
    if(x&1) {
        int totalV = x*(x - 1) / 2 + 1;
        return totalV >= n;
    }
    else {
        int totalV = x*(x - 1) / 2 - x / 2 + 1;
        return totalV >= n;
    }
}

void sol(){
	int n; cin >> n;
	
    int minEle, l = 0, r = n;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(check(mid, n)) {
            r = mid - 1;
            minEle = mid;
        }
        else l = mid + 1;
    }

    rep(i, 20000) {
        graph[i].clear();
    }
    rep(i, MAXN) vis[i] = 0;

    int idx = 0;
    rep(i, minEle) {
        rep(j, i + 1, minEle) {
            if(ans%2 == 0 && i%2 == 0 && j == i + 1) continue;
            graph[i].pb({j, idx});
            graph[j].pb({i, idx++});
        }
    }

    dfs(0, minEle);
    rep(i, minEle) {
        cout << arr[i] << " \n"[i == minEle - 1];
    }
    
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