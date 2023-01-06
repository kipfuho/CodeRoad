#include<iostream>
#include<math.h>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int s[n];
    for(int i=0;i<n;i++)cin>>s[i];
    int a=s[0]+s[n-1],b=s[n-1],c=s[0];
    for(int i=n-1;i>0;i--){
        if(s[i]+s[i-1]>a){
            a=s[i]+s[i-1];
            b=s[i-1];
            c=s[i];
        }
    }
    cout<<b<<" "<<c;
}