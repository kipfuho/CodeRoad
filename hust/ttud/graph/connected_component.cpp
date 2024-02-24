/*
A. CONNECTED COMPONENTS
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Given a undirected graph G=(V,E) where V={1,…,N} is the number of nodes and the set E has M edges. Compute number of connected components of G.

Input
Line 1: two positive integers N and M (1≤N≤105,1≤M≤105)
Line i+1 (i=1,…,M): contains two positive integers u and v which are endpoints of ith edge
Output
Write the number of connected components of G.

Example
inputCopy
8 8
1 2
1 7
1 8
2 7
4 5
4 6
5 6
7 8
outputCopy
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

int n, m, cc = 0;
vector<vector<int>> g;
bool visited[100001];

void dfs(int u){
    for(int v:g[u]){
		if(!visited[v]){
			visited[v] = true;
			dfs(v);
		}
	}
	return;
}

int main(){_
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> n >> m;
	g.resize(n+1, vector<int>());
	memset(visited, false, n+1);
	FOR(i, 1, m){
		int u, v; cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	FOR(i, 1, n){
		if(!visited[i]){
			cc++;
			dfs(i);
		}
	}
	cout << cc;
    return 0;
}