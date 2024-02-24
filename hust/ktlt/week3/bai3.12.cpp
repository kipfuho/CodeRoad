// Nguyen Dinh Ut Biu 20215317
// Bai3.12: Cho do thi vô huong G, hãy dem so duong di di 
// qua k canh và không di qua dinh nào quá mot lan.

#include <iostream>
#include <vector>

using namespace std;

// n: number of vertices
// k: number of edges each path must have
// m: number of edges
int n, k, m, count = 0;
vector<vector<int>> graph;
vector<bool> visited;

// get input and initiate some value
void input(){
    cin >> n >> k >> m;
    graph.resize(m + 1);
    visited.resize(n + 1, false);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

// using DFS to count
void countPaths(int u, int k) {
	// k == 0, our paths has k edges, increase count
    if (k == 0) {
        count ++;
    }

    visited[u] = true;

    for(int v : graph[u]) {
        if (!visited[v]) {
            countPaths(v, k - 1);
        }
    }

    visited[u] = false;
}

int main() {
	input();
	
	// Search from each of the vertices
    for (int i = 1; i <= n; i++) {
        countPaths(i, k);
    }

	// we need to divide by 2 because we have the 2 exact same paths, like a->e and e->a
    cout << count / 2 << endl;

    return 0;
}

