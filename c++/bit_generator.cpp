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

int bit[nmax], n;

void display(){
	FOR(i,0,n-1) cout<<bit[i];
	cout<<endl;
}

void TRY(int x){
	if(x==n) display();
	else{
		bit[x]=0;
		TRY(x+1);
		bit[x]=1;
		TRY(x+1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	TRY(0);
}