/*
Description
Given an undirected graph G=(V, E) in which V={1,…, N} is the set of nodes and |E|=M. You are required to write a program to check if G is a bipartite graph.

Input
Line 1 N and M (1≤N, M≤10
5
)
Line i+1 (i=1,…, M): u and v which are endpoints of the ith edge
Output
Write 1 if G is a bipartite graph and 0, otherwise.

Example
input
6 6
1 2
1 3
2 5
2 6
4 5
4 6
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

int n, m, cluster[100001];
bool visited[100001];
vector<vector<int>> g;

bool dfs(int u){
    bool valid = true;
    for(int v:g[u]){
        if(cluster[v] == cluster[u]) return false;
        if(visited[v]) continue;
        visited[v] = true;
        cluster[v] = -cluster[u];
        valid = dfs(v);
    }
    return valid;
}

int main(){_
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> n >> m;
    g.resize(n+1, vector<int>());
    FOR(i, 1, m){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cluster[1] = 1;
    bool valid = true;
    FOR(i, 1, n){
        if(!visited[i]){
            visited[i] = true;
            valid = valid && dfs(i);
        }
    }
    cout << valid;
    return 0;
}