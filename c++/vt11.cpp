#include<iostream>
#include<math.h>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int s[n];
    for(int i=0;i<n;i++)cin>>s[i];
    sort(s+1,s+n-1);
    for(int i=0;i<n;i++)cout<<s[i]<<" ";
}