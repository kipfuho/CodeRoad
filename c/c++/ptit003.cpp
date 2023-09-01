#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin>>n;
    int D[n], A[n+1], B[n];
    FOR(i,1,n-1){
        cin>>D[i];
        if(D[i]==0){
            cout<<-1;
            return 0;
        }
    }
    B[0]=A[1]=D[1];
    int min=A[1];
    FOR(i,2,n){
        A[i]=A[i-1]+D[i-1];
        B[i-1]=A[i];
        if(min>A[i]) min=A[i];
    }
    min=-min+1;
    sort(B,B+n);
    FOR(i,1,n-1){
        if(B[i]-B[i-1]!=1){
            cout<<-1;
            return 0;
        }
    }
    FOR(i,1,n) cout<<A[i]+min<<" ";
}