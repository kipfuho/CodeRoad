//hash_key=s1.base^n-1+s2.base^n-1+....+sn
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
using namespace std;

const ll nmax=2000;
const ll base=311;
const ll MOD=1e9+7;

ull POW[nmax], hashP[nmax];

int search(ull h,string s){
    hashP[0]=0; int res=0, n=s.size();
    FOR(i,1,n) hashP[i]=(hashP[i-1]*base+s[i])%MOD;
    FOR(i,1,n-8){
        ull t=(hashP[i+8]-hashP[i-1]*POW[9]+MOD*MOD)%MOD;
        if(t==h) res++;
    }
    return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ull hash=0; string s="luyencode"; int n;
    POW[0]=1; FOR(i,1,50) POW[i]=(POW[i-1]*base)%MOD;
    FOR(i,1,9) hash=(hash*base+s[i-1])%MOD;
    cin>>n>>s;
	cout<<search(hash,' '+s);
}