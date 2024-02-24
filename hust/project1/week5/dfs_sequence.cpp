#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<vector<int>> g;
bool visited[100001];

void dfs(int u){
    cout << u << " ";
    for(int v:g[u]){
        if(!visited[v]){
            visited[v] = true;
            dfs(v);
        }
    }
    return;
}

int main(){_
    int n, m; cin >> n >> m;
    g.resize(n+1, vector<int>());
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        sort(g[i].begin(), g[i].end());
    }
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            visited[i] = true;
            dfs(i);
        }
    }
    
    return 0;
}