#include<bits/stdc++.h>
#include<algorithm>
#define ll long long
#define FOR(i,l,r) for(int i=l;i<r;i++)
using namespace std;

string s;

string HEX[16]={"0","1","10","11","100","101","110","111","1000","1001","1010","1011","1100","1101","1110","1111"};

string fill(int y,string end){
    string res="";
    while(y){
        res+="0";
        y--;
    }
    return (res+end);
}

void conv(string x){
    int n=x.size(),l=1;
    int p=((x[0]-'0')>9?(x[0]-'0'-7):(x[0]-'0'));
    cout<<HEX[p];
    if(n>1){
        while(l<n){
            p=((x[l]-'0')>9?(x[l]-'0'-7):(x[l]-'0'));
            if(p<=1) cout<<fill(3,HEX[p]);
            else if(p<=3) cout<<fill(2,HEX[p]);
            else if(p<=7) cout<<fill(1,HEX[p]);
            else cout<<HEX[p];
            l++;
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>s;
        conv(s);
        cout<<endl;
    }
}