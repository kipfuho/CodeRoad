/**
Description
Given a directed graph G = (V,E) in which V = {1,2,...,n) is the set of nodes. Each arc (u,v) has a non-negative weight w(u,v). 
Given two nodes s and t of G. Find the shortest path from s to t on G.
Input
Line 1: contains two integers n and m which are the number of nodes and the number of arcs of G (1 <= n <= 100000)
Line i + 1(i = 1,2,...,m): contains 3 integers u, v, w in which w is the weight of arc(u,v) (0 <= w <= 100000)
Line m+2: contains two integers s and t
Output
Write the weight of the shortest path found or write -1 if no path from s to t was found
Example
Input
5 7
2 5 87
1 2 97
4 5 78
3 1 72
1 4 19
2 3 63
5 1 18
1 5

Output
97

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
    vector<vector<pair<int, int>>> graph(n+1);
    vector<int> D(n+1, 1<<30);
    vector<bool> visited(n+1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> heap;
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    int start, end; cin >> start >> end;
    D[start] = 0;
    heap.push({start, 0});
    while(!heap.empty()){
        pair<int, int> top = heap.top();
        heap.pop();

        int u = top.first, cost = top.second;
        if(visited[u]) continue;
        visited[u] = true;

        for(auto& edge:graph[u]){
            if(D[edge.first] > cost + edge.second){
                D[edge.first] = cost + edge.second;
                heap.push({edge.first, D[edge.first]});
            }
        }
    }
    cout << D[end];
    return 0;
}