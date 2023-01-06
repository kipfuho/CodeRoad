#include<bits/stdc++.h>
#include<vector>
#include<stack>
#include<queue>
#define ll long long
#define ull unsigned long long
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
using namespace std;

vector<int> a; int n, limit=1;

void display(){
    FOR(i,1,n) cout<<a[i]<<" ";
    cout<<endl;
}

void TRY(int x){
    if(x==limit) return;
    display();
    int j, k;
    FOD(i,n,2) if(a[i]>a[i-1]) {j=i-1; break;}
    k=j;
    FOR(i,j+1,n){
        if(k==j && a[i]>a[j]) k=i;
        else if(a[i]>a[j] && a[i]<a[k]) k=i;
    }
    int t=a[j]; a[j]=a[k]; a[k]=t;
    reverse(a.begin()+j+1,a.end());
    TRY(x+1);
}

int main(){
    cin>>n;
    a.push_back(0);
    FOR(i,1,n){
        a.push_back(i);
        limit*=i;
    }
    TRY(0);
}