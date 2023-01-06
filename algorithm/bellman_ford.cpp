//single-source bellman ford shortest path algorithm, can do negative weight
#include<bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)

using namespace std;

int const nmax=1e6+1;
ll const INF=200000000000000000LL;

struct edge{
    int u;
    int v;
    ll w;
};

void bellman_ford(int n, int S, vector<edge> &e, vector<int> &trace, vector<ll> &D){
    D.resize(n,INF);
    trace.resize(n,-1);

    D[S]=0;
    FOR(T,1,n-1){
        for(auto E : e){
            int u=E.u;
            int v=E.v;
            ll w=E.w;

            if(D[u]!=INF && D[v]>D[u]+w){
                D[v]=D[u]+w;
                trace[v]=u;
            }
        }
    }
    FOR(T,1,n){
        for(auto E : e){
            int u=E.u;
            int v=E.v;
            ll w=E.w;

            if(D[u]!=INF && D[v]>D[u]+w){
                D[v]=-INF;
                trace[v]=u;
            }
        }
    }
}

vector<int> retrace(int n, int u, vector<int> &trace){
    if(trace[u]=-1){
        return vector<int> {0};
    }

    vector<int> path;
    while(trace[u]!=-1){
        path.push_back(trace[u]);
        u=trace[u];
    }
    
    return path;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

    vector<edge> e;
    vector<int> trace;
    vector<ll> D;
    int n,m,S;
    cin>>n>>m>>S;

    FOR(i,1,m){
        int u,v,w;
        cin>>u>>v>>w;
        edge *E=new edge;
        E->u=u;
        E->v=v;
        E->w=w;
        e.push_back(*E);
    }

    bellman_ford(n,S,e,trace,D);

    for(auto x : D){
        cout<<x<<" ";
    }
}