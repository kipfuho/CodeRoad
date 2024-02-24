/*
Description
Given a directed graph G = (V, E) in which V = {1, 2, ..., n} is the set of nodes, and w(u,v) is the weight (length) of the arc(u,v). Compute d(u,v) - the length of the shortest path from u to v in G, for all u,v in V.
Input
Line 1: contains 2 positive integers n and m (1 <= n,m <= 10000)
Line i+1 (i = 1, 2, ..., m): contains 3 positive integers u, v, w in which w is the weight of the arc (u,v) (1 <= w <= 1000)
Output
Line i (i = 1, 2, ..., n): wirte the ith row of the matrix d (if there is not any path from node i to node j, then d(i,j) = -1)
Example
Input
4 9 
1 2 9 
1 3 7 
1 4 2 
2 1 1 
2 4 5 
3 4 6 
3 2 2 
4 1 5 
4 2 8
Output
0 9 7 2  
1 0 8 3  
3 2 0 5  
5 8 12 0
*/

#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

class compare{
    public:
    bool operator() (pair<int, int> p2, pair<int, int> p1){
        return p2.second > p1.second;
    }
};

int main(){_
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> g(n+1);
    vector<vector<int>> floyd(n+1, vector<int>(n+1, 1<<30));
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> heap;
    vector<bool> visited(n+1);
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    for(int i = 1; i <= n; i++){
        for(int i = 1; i <= n; i++) visited[i] = false;
        heap.push({i, 0});
        floyd[i][i] = 0;
        while(!heap.empty()){
            pair<int, int> top = heap.top();
            heap.pop();

            int u = top.first, cost = top.second;
            if(visited[u]) continue;
            visited[u] = true;

            for(auto& edge:g[u]){
                if(floyd[i][edge.first] > cost + edge.second){
                    floyd[i][edge.first] = cost + edge.second;
                    heap.push({edge.first, floyd[i][edge.first]});
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << floyd[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}