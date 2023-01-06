#include<bits/stdc++.h>
#include<algorithm>
#define M 1000000
using namespace std;
int main(){
    int p[M+1]={0};
    for(int i=2;i<=M;i++){
        if(p[i]==-1) continue;
        int j=2;
        while(j*i<=M){
            p[j*i]=-1;
            j++;
        }
    }
    long long n;
    cin>>n;
    int a=0;
    if(n%2==0){
        a++;
        while(n%2==0){
            p[2]++;
            n/=2;
        }
    }
    for(int i=3;i<=sqrt(n);i++){
        if(p[i]==0 && n%i==0){
            a++;
            while(n%i==0){
                p[i]++;
                n/=i;
            }
        }
    }
    if(n>1){
        p[n]++;
        a++;
    }
    cout<<a<<endl;
    for(int i=0;i<=M;i++){
        if(p[i]>0) cout<<i<<" "<<p[i]<<endl;
    }
}