#include<iostream>
#include<math.h>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int s[n];
    for(int i=0;i<n;i++)cin>>s[i];
    sort(s,s+n,greater());
    for(int i=0;i<n;i++)cout<<s[i]<<" ";
}