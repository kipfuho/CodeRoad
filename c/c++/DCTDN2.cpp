//creating best config for incresing list
#include<bits/stdc++.h>
#include<vector>
#define ll long long
#define ull unsigned long long
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin>>n; int b[n+1];
    vector <int> a(n,INT_MAX);
	FOR(i,1,n) cin>>b[i];
	int res=0,t;
    FOR(i,1,n){
        t=lower_bound(a.begin(),a.end(),b[i])-a.begin();
        a[t]=b[i];
        res=max(res,t);
    }
    cout<<res+1;
}