#include<bits/stdc++.h>
#include<algorithm>
#define ll long long
#define FOR(i,l,r) for(int i=l;i<r;i++)
using namespace std;

char HEX[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F',};

string s;

ll conv2(string s){
    int n=s.size(),j=0;
    ll res=0;
    for(int i=0;i<n;i++){
        res+=(ll)(pow(2,j)*(s[i]-'0'));
        j++;
    }
    return res;
}

void conv16(string s){
    int n=s.size(),temp=n,l=0,len=1;
    char res[16];
    string sub;
    reverse(s.begin(),s.end());
    while(temp>4){
        sub=s.substr(l,4);
        res[len-1]=HEX[conv2(sub)];
        len++;
        l+=4;
        temp-=4;
    }
    sub=s.substr(l,4);
    res[len-1]=HEX[conv2(sub)];
    for(int i=len-1;i>=0;i--) cout<<res[i];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>s;
        conv16(s);
        cout<<endl;
    }
}