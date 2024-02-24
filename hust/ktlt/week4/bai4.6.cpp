// Nguyen Dinh Ut Biu
// B�i 4.6: Viet h�m void bfs(vector< list<int> > adj) thuc hien thuat 
// to�n BFS kh�ng su dung de quy tr�n do thi bieu dien bang danh s�ch ke.
// �o thi c� n dinh duoc d�nh so tu 1 den n. Thuat to�n BFS xuat ph�t tu 
// dunh 1. C�c dinh duoc tham theo thu tu uu ti�n tu tr�i sang phai trong
// danh s�ch ke. Y�u cau h�m tra ra thu tu c�c dinh duoc tham 
// (nhung dinh kh�ng the tham tui dinh 1 th� kh�ng phai in ra).

#include <iostream>
#include <vector>
#include <stack>
#include <list>
using namespace std;

void bfs(vector< list<int> > adj) {
    queue<int> Q;
    vector<bool> visited(adj.size());
    Q.push(1); // Bat dau tu dinh so 1
    
    while(!Q.empty()){
    	// get front from queue
        int u = Q.front();
        Q.pop();
        // if not visited, visit and add adjacent vertices to queue
        if(!visited[u]){
            visited[u] = true;
            cout << u << endl;
            for(auto& v:adj[u]){
                if(!visited[v]) Q.push(v);
            }
        }
    }
}

int main() {
    int n, m; 
	cin >> n >> m;
	vector< list<int> > adj;
	adj.resize(n + 1);
	while(m--){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	dfs(adj);
    return 0;
}
