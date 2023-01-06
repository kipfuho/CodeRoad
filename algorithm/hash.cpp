//hash_key=s1+s2.base+s3.base^2+s4.base^3+...
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define FOR(i,l,r) for(int i=l;i<=r;i++)

const ll nmax=200006;
const ll base=31;
const ll MOD=1e9+7;

string s; int n,k;
ull POW[nmax], hashP[nmax];

bool compare(ull h,string s){
    hashP[0]=0;
    FOR(i,1,2*n) hashP[i]=POW[i-1]*(s[i]-'a'+1)+hashP[i-1];
    FOR(i,1,n){
        ull t=hashP[i+n-1]-hashP[i-1];
        if(t==h*POW[i-1]) return 1;
    }
    return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k>>s; ull hash=0;
    POW[0]=1; FOR(i,1,2*n) POW[i]=(POW[i-1]*base);
    FOR(i,0,n-1) hash+=(POW[i]*(s[i]-'a'+1));
	while(k--){
		cin>>s;
		if(compare(hash,' '+s+s)) cout<<"YES";
        else cout<<"NO";
        cout<<endl;
	}
}
