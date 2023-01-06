#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,res,t=0; cin>>n;
    res=n;
    while(res>9){
        n=res;
        while(n>0){
            t+=n%10;
            n/=10;
        }
        res=t;
        t=0;
    }
    cout<<res;
}