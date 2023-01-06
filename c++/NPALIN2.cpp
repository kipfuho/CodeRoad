#include<bits/stdc++.h>
#include<algorithm>
#define ll long long
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
using namespace std;
ll x2str(string s,int n){
    string x=s;
    if(n&1) s.pop_back();
    reverse(s.begin(),s.end());
    x+=s;
    return stoll(x);
}
ll count(string s){
    int len=s.size();
    int mid=(len+1)/2;
    string x=s.substr(0,mid);
    if(len==1) return stoll(s);
    if(x2str(x,len)>stoll(s)) x=to_string(stoll(x)-1);
    return (stoll(x)-1) + (len&1?pow(10,x.size()-1):pow(10,x.size()));
}
int main(){
    ll l,r;
    while(cin>>l>>r){
        l--;
        cout<<count(to_string(r))-count(to_string(l))<<endl;
    }
}