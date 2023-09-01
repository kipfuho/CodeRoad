//root is 1st vertex
#include<bits/stdc++.h>
#include<vector>
#define ll long long
#define ull unsigned long long
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
using namespace std;

const int nmax=1e5+1;
vector <int> g[nmax];

int toleaf[nmax];
int maxlength[nmax];

void dfs(int u,int pre){
    toleaf[u]=1; maxlength[u]=0;
    int t1=0,t2=0;
    for(int v:g[u]){
        if(v==pre) continue;
        dfs(v,u);
        toleaf[u]=max(toleaf[u],toleaf[v]+1);
        if(toleaf[v]>t2) t2=toleaf[v];
        if(toleaf[v]>t1){
            t2=t1;
            t1=toleaf[v];
        }
    }
    maxlength[u]=t1+t2;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,a,b; cin>>n;
    FOR(i,1,n-1){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0);
    FOR(i,1,n) cout<<maxlength[i]<<" ";
}