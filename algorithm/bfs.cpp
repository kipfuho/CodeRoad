#include<bits/stdc++.h>
#include<vector>
#define ll long long
#define ull unsigned long long
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
using namespace std;

const int maxN=100001;

int n,m;
//int d[maxN], par[maxN];
bool Visit[maxN];
vector <int> g[maxN];

void igraph(){
    int a,b;
    FOR(i,1,m){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
}

void bfs(int s) { // s is root
    //fill_n(d, n + 1, 0);
    //fill_n(par, n + 1, -1);
    //fill_n(Visit, n + 1, false);

    queue <int> q;
    q.push(s);
    Visit[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        //cout<<u<<endl; // order the vertex is explored
        for (auto v : g[u]) {
            if (!Visit[v]) {
                //d[v]     = d[u] + 1;
                //par[v]   = u;
                Visit[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
    igraph();
    fill_n(Visit, n + 1, false);
    FOR(i,1,n){
        if(!Visit[i]) bfs(i);
    }
}