//tim` so nghich the' : j<i -> a[i]<a[j]
#include<bits/stdc++.h>
#include<algorithm>
#define ll long long
#define FOR(i,l,r) for(int i=l;i<r;i++)
using namespace std;

const int nmax=1e5+7;

int n;
int a[nmax];
ll bit[nmax];

ll getsum(int x){
    ll retr=0;
    while(x>0){
        retr+=bit[x];
        x-=x&(-x);
    }
    return retr;
}

void update(int x, int val){
    while(x<=nmax){
        bit[x]+=val;
        x+=x&(-x);
    }
}

int main(){
    ll res=0;
    cin>>n;
    FOR(i,1,n+1) cin>>a[i];
    memset(bit,0,sizeof(bit));
    for(int i=n;i>=1;i--){
        res+=getsum(a[i]-1);
        update(a[i],1);
    }
    cout<<res;
}