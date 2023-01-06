#include<bits/stdc++.h>
#include<algorithm>
#define ll long long
#define FOR(i,l,r) for(int i=l;i<r;i++)
using namespace std;

char HEX[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F',};

void conv(ll x){
    string retr="";
    while(x>=16){
        retr+=HEX[x%16];
        x/=16;
    }
    retr+=HEX[x];
    reverse(retr.begin(),retr.end());
    cout<<retr;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        conv(n);
        cout<<endl;
    }
}