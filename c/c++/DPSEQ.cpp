#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main(){
    int N,k;
    cin>>N>>k;
    int st[N+1],mt[N+1];
    for(int i=0;i<=N;i++) mt[i]=-1000000000;
    for(int i=1;i<=N;i++) cin>>st[i];
    mt[0]=0;
    for(int i=1;i<=N;i++){
        for(int j=0;j<i;j++){
            if(i-j<=k){
                mt[i]=max(mt[i],mt[j]+st[i]);
            }
        }
    }
    int s=mt[0];
    for(int i=1;i<=N;i++){
        if(mt[i]>s)s=mt[i];
    }
    cout<<s;
}