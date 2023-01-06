//f[0]='a' f[1]='b' f[i]=f[i-2]+f[i] -> f[2]="ab"
#include<bits/stdc++.h>
#define ll long long
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
using namespace std;

ll f[51];

/*ll solve(int n, int k){
    if(n==1) return 0LL;
    if(n==0 && k==1) return 1LL;
    if(n==0 && k==0) return 0LL;
    if(k>=f[n-2]){
        int k2=k-f[n-2], k1=k-k2;
        return solve(n-2,k1) + solve(n-1,k2);
    }
    return solve(n-2,k);
}*/

ll solve(int n, int k){
    int a=n%2; ll res=0;
    while(k){
        int i=40-a;
        while(f[i]>k) i-=2;
        k-=f[i];
        res+=f[i-2];
        a=1-a;
    }
    return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
    f[0]=1; f[1]=0;
	FOR(i,2,50) f[i]=f[i-2]+f[i-1];
	int t; cin>>t;
	while(t--){
		int n,k; cin>>n>>k;
		cout<<solve(n,k)<<endl;
	}
}
