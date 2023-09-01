#include<bits/stdc++.h>
#include<algorithm>
#include<set>
#define ll long long
#define FOR(i,l,r) for(int i=l;i<r;i++)
using namespace std;

int main(){
    int n,S;
    cin>>n>>S;
    int c[n+1],p[n+1];
    FOR(i,1,n+1) cin>>c[i];
    FOR(i,1,n+1) cin>>p[i];
    int F[n+1][S+1];
    FOR(i,0,n+1){
        FOR(j,0,S+1){
            F[i][j]=0;
        }
    }
    FOR(i,1,n+1){
        int pre=0;
        FOR(j,1,S+1){
            if(j>=c[i]) F[i][j]=max(F[i-1][j-c[i]]+p[i],F[i-1][j]);
            else F[i][j]=F[i-1][j];
        }
    }
    cout<<F[n][S];
}