/*
Description
Given a directed graph G=(V,E) where V={1,. . ., N} is the number of nodes and the set E has M arcs. Compute number of strongly connected components of G
Input
Line 1: two positive integers N and M (1 <= N <= 10
5
, 1 <= M <= 10
6
)
Line i+1 (i=1,. . ., M\): contains two positive integers u and v which are endpoints of i
th
 arc
Output
Write the number of strongly connected components of G
Example
Input
8 13
1 2
1 8
2 3
2 6
3 6
4 3
4 6
5 4
6 5
7 1
7 2
7 6
8 7
Output
3
*/

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

int n, m, timeDFS = 0, scc = 0;
vector<vector<int>> g;
int num[100001], low[100001];
bool visited[100001];
stack<int> st;

void dfs(int u){
    st.push(u);
    num[u] = low[u] = ++timeDFS;
    for(auto v:g[u]){
        if(visited[v]) continue;
        if(!num[v]){
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else{
            low[u] = min(low[u], num[v]);
        }
    }
    if(num[u] == low[u]){
        scc++;
        int v;
        do{
            v = st.top();
            visited[v] = true;
            st.pop();
        } while(v != u);
    }
    return;
}

int main(){_
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> n >> m;
    g.resize(n + 1, vector<int>());
    memset(num, 0, 4*(n+1));
    memset(visited, false, n+1);
    FOR(i, 1, m){
        int u, v; cin >> u >> v;
        g[u].pb(v);
    }
    FOR(i, 1, n){
        if(!num[i]){
            dfs(i);
        }
    }
    cout << scc;
    return 0;
}