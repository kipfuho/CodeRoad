#include<iostream>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    double fac[n+1];
    fac[0]=1;
    for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i;
    for(int i=1;i<=n;i++) cout<<fac[i]<<endl;
    cout<<fac[n]/(fac[k]*fac[n-k]);
}