/*
Description
Given a network G = (V, E) which is a directed weighted graph. Node s is the source and node t is the target. c(u,v) is the 
capacity of the arc (u,v). Find the maximum flow on G.
Input
•Line 1: two positive integers N and M (1 <= N <= 10^4, 1 <= M <= 10^6)
•Line 2: contains 2 positive integers s and t
•Line i+2 (I = 1,. . ., M): contains two positive integers u and v which are endpoints of i_th arc
Output 
Write the value of the max-flow found

Example
Input
7 12
6 7
1 7 7
2 3 6
2 5 6
3 1 6
3 7 11
4 1 7
4 2 4
4 5 5
5 1 4
5 3 4
6 2 8
6 4 10
Output
17
*/

#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int n, m, s, t;
vector<bool> visited;
vector<vector<int>> graph, cur_weight, max_weight;
vector<pair<int, int>> trace;

// find augment path and return the increment of the path using bfs
int find_augmentpath(int start, int end){
    int weight = INT_MAX, u, v, possible_increment;
    for(int i = 1; i <= n; i++) visited[i] = false;
    
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        u = q.front();
        q.pop();

        for(auto& v:graph[u]){
            possible_increment = max_weight[u][v] - cur_weight[u][v];
            if(possible_increment > 0 && !visited[v]){
                q.push(v);
                visited[v] = true;
                trace[v] = {u, possible_increment};
                // found a path
                if(v == end){
                    // find min increment first
                    pair<int, int> temp = trace[v];
                    while(temp.first != 0){
                        weight = min(weight, temp.second);
                        temp = trace[temp.first];
                    }

                    // update cur_weight
                    temp = trace[v];
                    int temp2 = v;
                    while(temp.first != 0){
                        cur_weight[temp.first][temp2] += weight;
                        temp2 = temp.first;
                        temp = trace[temp.first];
                    }
                    return weight;
                }
            }
        }
    }
    return 0;
}

int ford_fullkerson(int start, int end){
    int maxflow = 0, possible_increment = find_augmentpath(start, end);
    while(possible_increment > 0){
        maxflow += possible_increment;
        possible_increment = find_augmentpath(start, end);
    }
    return maxflow;
}

int main(){_
    cin >> n >> m >> s >> t;
    visited.resize(n+1, false);
    graph.resize(n+1);
    cur_weight.resize(n+1, vector<int>(n+1, 0));
    max_weight.resize(n+1, vector<int>(n+1, 0));
    trace.resize(n+1, {0, 0});

    for(int i = 0; i < m; i++){
        int u, v, c; cin >> u >> v >> c;
        graph[u].push_back(v);
        max_weight[u][v] = c;
    }

    cout << ford_fullkerson(s, t);
    return 0;
}