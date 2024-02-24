// Nguyen Dinh Ut Biu
// Bài 4.5: Viet hàm void dfs(vector< list<int> > adj) thuc hien thuat 
// toán DFS không su dung de quy trên do thi bieu dien bang danh sách ke.
// Ðo thi có n dinh duoc dánh so tu 1 den n. Thuat toán DFS xuat phát tu 
// dunh 1. Các dinh duoc tham theo thu tu uu tiên tu trái sang phai trong
// danh sách ke. Yêu cau hàm tra ra thu tu các dinh duoc tham 
// (nhung dinh không the tham tui dinh 1 thì không phai in ra).

#include <iostream>
#include <vector>
#include <stack>
#include <list>
using namespace std;

void dfs(vector< list<int> > adj) {
    stack<int> S;
    vector<bool> visited(adj.size());
    S.push(1); // Bat dau tu dunh so 1
    
    while(!S.empty()){
    	// pop top from stack
        int u = S.top();
        S.pop();
        // if not visited, visit and add adjacent vertices to stack
        if(!visited[u]){
            visited[u] = true;
            cout << u << endl;s
            // reverse because that's the order this problem want
            adj[u].reverse();
            for(auto& v:adj[u]){
                if(!visited[v]) S.push(v);
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
