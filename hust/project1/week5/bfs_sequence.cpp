#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){_
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n+1, vector<int>());
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        sort(g[i].begin(), g[i].end());
    }
    queue<int> q;
    vector<bool> visit(n+1, false);
    for(int i = 1; i <= n; i++){
        if(!visit[i]){
            q.push(i);
            visit[i] = true;
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            cout << u << " ";
            for(auto& v:g[u]){
                if(!visit[v]){
                    q.push(v);
                    visit[v] = true;
                }
            }
        }
    }
    return 0;
}