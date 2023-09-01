#include<bits/stdc++.h>
#include<vector>

using namespace std;

#define FOR(i,l,r) for(int i=l;i<=r;i++)

int const nmax=1e6+1;
vector<int> g[nmax];
int low[nmax], num[nmax], tail[nmax];
int timeDFS=0;
int vertexNumber; // biến tạm lưu giữ số đỉnh của thành phần liên thông hiện tại

void dfs(int u, int pre){
    vertexNumber++;
    num[u]=low[u]=++timeDFS;
    for(auto v:g[u]){
        if(v==pre) continue;
        if(!num[v]){
            dfs(v,u);
            low[u]=min(low[u],low[v]);
        }
        else low[u]=min(low[u], num[v]);
    }
    tail[u]=timeDFS;
}

// Tìm số thành phần liên thông của đồ thị
vector<int> components; // lưu trữ số đỉnh của từng thành phần liên thông
int countConnectedComponents(int n) {
    int count = 0;

    for (int i = 0; i < n; ++i) {
        if (!num[i]) {
            dfs(i, -1);
            components.push_back(vertexNumber);
            vertexNumber = 0;
            ++count;
        }
    }

    return count;
}

int main(){
    int n,m; cin>>n>>m;
    int u, v;
    while(cin >> u >> v){
        g[u].push_back(v);
        g[v].push_back(u);
    }
    countConnectedComponents(n);
    long long res = 0;
    for(int i = 0; i < components.size() - 1; i++){
        for(int j = i + 1; j < components.size(); j++){
            res += components[i]*components[j];
        }
    }
    cout << res;
}