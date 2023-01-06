#include<bits/stdc++.h>
#define ll long long
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
using namespace std;

void getZ(int Z[],string s);

int search(string pattern, string text){
	string concat=pattern+"$"+text;
	int len=concat.size(),n=concat.size() , res=0;
	int Z[len];
	getZ(Z,concat);
	FOR(i,1,n) if(Z[i]==9) res++;
	return res;
}

void getZ(int Z[],string text){
	int L,R,k; int n=text.size();
	L=R=0;
	FOR(i,1,n){
		if(i>R){
			L=R=i;
			while(R<n && text[R-L]==text[R]) R++;
			Z[i]=R-L;
			R--;
		}
		else{
			k=i-L;
			if(Z[k]<R-k+1) Z[i]=Z[k];
			else{
				L=i;
				while(R<n && text[R-L]==text[R]) R++;
				Z[i]=R-L;
				R--;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; string s;
	cin>>n>>s;
	cout<<search("luyencode",s);
}
