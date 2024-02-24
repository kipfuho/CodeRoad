/*
Description
A project has n tasks 1,. . ., n. Task i has duration d(i) to be completed (i=1,. . ., n). There are precedence constraints between tasks represented by a set Q of pairs: for each (i,j)  in Q, task j cannot be started before the completion of task i. Compute the earliest completion time  of the project.
Input
Line 1: contains n and m (1 <= n <= 10
4
, 1 <= m <= 200000)
Line 2: contains d(1),. . ., d(n) (1 <= d(i) <= 1000)
Line i+3 (i=1,. . ., m) : contains i and j : task j cannot be started to execute before the completion of task i
Output
Write the earliest completion time of the project.
Example
Input
9 13
5 3 1 2 6 4 3 1 4
1 3
1 5
1 6
2 1
2 3
3 5
4 1
4 2
4 6
5 8
7 9
9 5
9 8

Output
18
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

int n, m, d[10001], length[10001];
bool check[10001], starter[10001];
vector<vector<int>> g;
vector<int> start_vertex;

void dfs(int u){
    for(int v:g[u]){
        if(length[u] + d[v] <= length[v]) continue;
        length[v] = length[u] + d[v];
        dfs(v);
    }
    return;
}

int main(){_
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> n >> m;
    g.resize(n+1, vector<int>());
    memset(check, false, n + 1);
    memset(starter, false, n + 1);
    memset(length, 0, 4*(n+1));
    FOR(i, 1, n) cin >> d[i];
    FOR(i, 1, m){
        int u, v; cin >> u >> v;
        check[v] = true;
        if(!check[u]){
            if(starter[v]){
                starter[v] = false;
            }
            starter[u] = true;
        }
        g[u].push_back(v);
    }
    FOR(i, 1, n){
        if(starter[i]) start_vertex.push_back(i);
    }
    for(auto u:start_vertex){
        length[u] = d[u];
        dfs(u);
    }
    int maxlength = 0;
    FOR(i, 1, n) maxlength = max(length[i], maxlength);
    cout << maxlength;
    return 0;
}