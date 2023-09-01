//#include "data_structures\fenwick_tree.cpp"
//#include "data_structures\linked_list.cpp"

#include<bits/stdc++.h>
#include<vector>
#include<stack>
#include<queue>
#define ll long long
#define ull unsigned long long
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin>>n;
	int a[n];
	FOR(i,0,n-1) cin>>a[i];
	sort(a,a+n);
	FOR(i,0,n-1) cout<<a[i]<<" ";
}