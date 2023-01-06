#include<bits/stdc++.h>
#include<vector>

using namespace std;

#define FOR(i,l,r) for(int i=l;i<=r;i++)

int const nmax=1e6+1;
vector<int> g[nmax];
int low[nmax], num[nmax], tail[nmax];
int timeDFS=0;

void dfs(int u, int pre){
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

int main(){
    int n,m; cin>>n>>m;
    FOR(i,1,m){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    FOR(i,1,n) cout<<num[i]<<" ";
    cout<<endl;
    FOR(i,1,n) cout<<low[i]<<" ";
    cout<<endl;
    FOR(i,1,n) cout<<tail[i]<<" ";
    cout<<endl;
}