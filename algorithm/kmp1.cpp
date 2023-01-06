#include<bits/stdc++.h>
#include<vector>
#define ll long long
#define ull unsigned long long
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
using namespace std;

void preprocess(int pi[], int m, string pat){
    pi[1]=0; int k=0;
    FOR(i,2,m){
        while(k>0 && pat[k+1]!=pat[i]) k=pi[k];
        if(pat[k+1]==pat[i]) k++;
        pi[i]=k;
    }
}

void search(string text, string pat){
    int n=text.size(), m=pat.size();
    int pi[m+1];
    preprocess(pi,m,pat);
    int k=0;
    FOR(i,1,n){
        while(k>0 && pat[k+1]!=text[i]) k=pi[k];
        if(pat[k+1]==text[i]) k++;
        if(k==m){
            cout<<"Match at position "<<i-m+1<<endl;
            k=pi[k];
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	search(" ABABDABACDABABCABAB"," ABABCABAB");
}