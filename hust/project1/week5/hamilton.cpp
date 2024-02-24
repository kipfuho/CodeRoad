#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<vector<int>> g(10001, vector<int>());
int visited[10001], n, m, is_hamilton;

void TRY(int node, int count){
    if(is_hamilton) return;
    visited[node] = 1;
    for(auto x:g[node]){
        if(x == 0 && count == n) is_hamilton = 1;
        if(is_hamilton) return;
        if(!visited[x]) TRY(x, count + 1);
    }
    visited[node] = 0;
    return;
}

int main(){_
    int t; cin >> t;
    while(t--){
        is_hamilton = 0; cin >> n >> m;
        memset(visited, 0, 4*n);
        for(int i = 0; i < m; i++){
            int u, v; cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        TRY(0, 1);
        cout << is_hamilton << endl;
    }
    return 0;
}