//sum from u-v, bit structure
#include<bits/stdc++.h>
#include<vector>
#define ll long long
#define ull unsigned long long
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
using namespace std;

const int nmax=100001;
int bit[nmax];

int n,q;

void update(int i, int x){
    while(i<=nmax){
        bit[i]+=x;
        i+=(i&(-i));
    }
}

ll getsum(int u, int v){
    ll retr=0;
    while(v>0){
        retr+=bit[v];
        v-=(v&(-v));
    }
    while(u>0){
        retr-=bit[u];
        u-=(u&(-u));
    }
    return retr;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin>>n>>q;
    bit[0]=0;
    FOR(i,1,n){
        int t; cin>>t;
        update(i,t);
    }
    FOR(i,1,q){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1) update(b,c);
        else cout<<getsum(b-1,c)<<" ";
    }
}