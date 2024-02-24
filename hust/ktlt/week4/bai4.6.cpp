// Nguyen Dinh Ut Biu
// Bài 4.6: Viet hàm void bfs(vector< list<int> > adj) thuc hien thuat 
// toán BFS không su dung de quy trên do thi bieu dien bang danh sách ke.
// Ðo thi có n dinh duoc dánh so tu 1 den n. Thuat toán BFS xuat phát tu 
// dunh 1. Các dinh duoc tham theo thu tu uu tiên tu trái sang phai trong
// danh sách ke. Yêu cau hàm tra ra thu tu các dinh duoc tham 
// (nhung dinh không the tham tui dinh 1 thì không phai in ra).

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
