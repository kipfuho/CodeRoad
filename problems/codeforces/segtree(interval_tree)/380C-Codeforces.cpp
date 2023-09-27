// https://codeforces.com/problemset/problem/380/C

#include<bits/stdc++.h>
#include<vector>
#include<stack>
#include<queue>
#define ll long long
#define ull unsigned long long
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
using namespace std;

string s;

struct Node{
    int optimal;
    int open;
    int close;
    Node(){

    }
    Node(int opt, int op, int cl){
        optimal=opt;
        open=op;
        close=cl;
    }
    Node operator + (const Node& right){
        Node res(0,0,0);
        int temp=min(this->open, right.close);
        res.optimal=this->optimal+right.optimal+temp*2;
        res.open=this->open+right.open-temp;
        res.close=this->close+right.close-temp;
        return res;
    }
} st[4000001];

void build(int id, int l, int r){
    if(l==r){
        if(s[l]=='(') st[id].open=1;
        else st[id].close=1;
    }
    else{
        int mid=(l+r)/2;
        build(2*id,l,mid);
        build(2*id+1,mid+1,r);
        st[id]=st[2*id]+st[2*id+1];
    }
}

Node query(int id, int l, int r, int u, int v){
    if(l>v||r<u) return Node(0,0,0);
    else if(l>=u && r<=v) return st[id];
    else{
        int mid=(l+r)/2;
        return query(2*id,l,mid,u,v)+query(2*id+1,mid+1,r,u,v);
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>s; int n=s.size();
    s=" "+s;
    build(1,1,n);
    int q; cin>>q;
    while(q--){
        int le,ri;
        cin>>le>>ri;
        cout<<query(1,1,n,le,ri).optimal<<endl;
    }
}