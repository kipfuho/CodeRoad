#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n=s.size();
    int a[n+1][n+1],res=0;
    for(int i=1;i<=n;i++) a[i][i]=1;
    for(int l=2;l<=n;l++){
        for(int i=1;i<=n-l+1;i++){
            int j=i+l-1;
            if(l==2 && s[i]==s[j]) a[i][j]=1;
            else{
                if(s[i]==s[j] && a[i+1][j-1]==1) a[i][j]=1;
                else a[i][j]=0;
            }
            if(a[i][j]==1) res=max(res,l);
        }
    }
    cout<<res;
}