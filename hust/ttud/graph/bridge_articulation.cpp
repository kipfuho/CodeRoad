/*
Description
Given an undirected graph containing N vertices and M edges, find all the articulation points and the bridges in the graph.
Input
The first line consists of two space-separated integers denoting N and M, 
M lines follow, each containing two space-separated integers X and Y denoting there is an edge between X and Y.
Output
One line consists of two integers denoting the number of articulation points and the number of bridges.
Example
Input
10 12
1 10
10 2
10 3
2 4
4 5
5 2
3 6
6 7
7 3
7 8
8 9
9 7
Output
4  3
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

int n, m, timeDFS = 0, articulation = 0, bridge = 0;
vector<vector<int>> g;
int num[100001], low[100001];

void dfs(int u, int pre){
    int child = 0;
    num[u] = low[u] = ++timeDFS;
    bool valid = false;
    for(auto v:g[u]){
        if(v == pre) continue;
        if(!num[v]){
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(num[v] == low[v]) bridge++;

            child++;
            if(u == pre){
                if(child > 1) valid = true;
            }
            else if(low[v] >= num[u]) valid = true;
        }
        else{
            low[u] = min(low[u], num[v]);
        }
    }
    if(valid) articulation++;
    return;
}

int main(){_
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> n >> m;
    g.resize(n + 1, vector<int>());
    memset(num, 0, 4*(n+1));
    FOR(i, 1, m){
        int u, v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    FOR(i, 1, n){
        if(!num[i]) dfs(i, i);
    }
    cout << articulation << " " << bridge;
    return 0;
}