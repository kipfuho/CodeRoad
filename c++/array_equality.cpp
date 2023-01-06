#include<bits/stdc++.h>
#include<vector>
#include<stack>
#include<queue>
#define ll long long
#define ull unsigned long long
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
using namespace std;

const int nmax=1e3+2;

int a[nmax], b[nmax], m, n, t;

int check(){
    cin>>m>>n;
    FOR(i,0,m-1) cin>>a[i];
    FOR(i,0,n-1) cin>>b[i];
    if(m!=n) return 0;
    else{
        FOR(i,0,m-1){
            if(a[i]!=b[i]) return 0;
        }
        return 1;
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
    while(t--){
        cout<<check()<<endl;
    }
}