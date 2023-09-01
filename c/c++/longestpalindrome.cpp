//brute force dynamic programming
#include<bits/stdc++.h>
#include<vector>
#define ll long long
#define ull unsigned long long
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
using namespace std;

string s; 
bool F[1001][1001];

string cal(string s){
    
    int l=0,r=0;
    memset(F,false,sizeof(F));
    int n=s.size();
    FOR(i,1,n) F[i][i]=true;
    FOR(i,1,n-1) F[i+1][i]=true;
    FOR(k,1,n-1){
        FOR(i,1,n-k){
            int j=k+i;
            F[i][j]=(F[i+1][j-1]&&(s[i]==s[j]));
            if(F[i][j]&&((j-i+1)>(r-l+1))){
                l=i;r=j;
            }
        }
    }
    string res=""; int j=0;
    FOR(i,l,r) res+=s[i];
    return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin>>s; s=" "+s;
    cout<<cal(s);
}