#include<bits/stdc++.h>
#include<algorithm>
#define ll long long
#define FOR(i,l,r) for(int i=l;i<r;i++)
using namespace std;

string s;

ll bconv16(string s){
    int n=s.size(),p=0,q=0;
    ll res=0;
    reverse(s.begin(),s.end());
    FOR(i,0,n){
        p=((s[i]-'0'>9)?(s[i]-'0'-7):(s[i]-'0'));
        res+=(ll)pow(16,q)*p;
        q++;
    }
    return res;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>s;
        cout<<bconv16(s)<<endl;
    }
}