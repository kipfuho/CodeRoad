#include<bits/stdc++.h>
#include<algorithm>
#define ll long long
using namespace std;

int l,r;

bool check(int x){
    int temp=x,a=0,s=0;
    while(x>0){
        a=a*10+x%10;
        s=s+x%10;
        x/=10;
    }
    return (a==temp && s%10==0) ? true : false;
}

void solve(){
    int res=0;
    for(int i=l;i<=r;i++){
        if(check(i)) res++;
    }
    cout<<res<<endl;
}

int main(){
    srand(time(NULL));
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin>>l>>r){
        solve();
    }
}