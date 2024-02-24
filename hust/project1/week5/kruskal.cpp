#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){_
    int n, m; cin >> n >> m;
    vector<pair<pair<int, int>, int>> edges;
    vector<int> cluster(n+1, 0);
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        edges.push_back({{u, v}, w});
    }
    
    auto cmp = [](pair<pair<int, int>, int> pair2, pair<pair<int, int>, int> pair1){
        if(pair2.second < pair1.second) return true;
        else return false;
    };
    sort(edges.begin(), edges.end(), cmp);

    for(int i = 1; i <= n; i++) cluster[i] = i;
    int min_weight = 0;
    for(auto& edge:edges){
        int u = edge.first.first, v = edge.first.second, w = edge.second;
        while(cluster[u] != u){ 
            cluster[u] = cluster[cluster[u]];
            u = cluster[u];
        }
        while(cluster[v] != v){
            cluster[v] = cluster[cluster[v]];
            v = cluster[v];
        }
        if(u != v){
            min_weight += w;
            cluster[u] = v;
        }
    }
    cout << min_weight;
    return 0;
}