// x is a substring of y if we can remove some chars of y to get x
#include<bits/stdc++.h>
#include<algorithm>
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
using namespace std;
int main(){
    string s;
    cin>>s;
    int n=s.size(),L[n+1][n+1];
    FOR(l,1,n){
        FOR(i,1,n-l+1){
            int j=i+l-1;
            if(l==1){
                L[i][j]=1;
                continue;
            }
            if(l==2){
                L[i][j]=1+(s[i-1]==s[j-1]);
                continue;
            }
            L[i][j]=max(L[i+1][j],L[i][j-1]);
            if(s[i-1]==s[j-1]) L[i][j]=max(L[i][j],L[i+1][j-1]+2);
        }
    }
    cout<<L[1][n];
}