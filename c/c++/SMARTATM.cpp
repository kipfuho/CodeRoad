#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main(){
    int n,M;
    cin>>n>>M;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int l[M+1];
    l[0]=0;
    for(int i=1;i<=M;i++) l[i]=1000000000;
    for(int i=1;i<=M;i++){
        for(int j=0;j<n;j++){
            if(i>=a[j]) l[i]=min(l[i],l[i-a[j]]+1);
        }
    }
    if(l[M]!=1000000000) cout<< l[M];
    else cout<<-1;
}