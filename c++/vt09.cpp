#include<iostream>
#include<math.h>
#include <bits/stdc++.h>
using namespace std;

int prime(int x){
    if(x==1) return 0;
    for(int i=2;i<=sqrt(x);i++) if(x%i==0) return 0;
    return 1;
}

int main(){
    int n;
    cin>>n;
    int s[n];
    for(int i=0;i<n;i++)cin>>s[i];
    sort(s,s+n);
    int t=0;
    for(int i=0;i<n;i++){
        if(prime(s[i])==1&&s[i]!=t){
            cout<<s[i]<<" ";
            t=s[i];
        }
    }
}