#include<iostream>
#include<math.h>
#define M 1000000
using namespace std;

int p[M+1];

void tinh(){
    int pre=1;
    for(int i=2;i<=M;i++) p[i]=0;
    for(int i=2;i<=sqrt(M);i++){
        if(p[i]==-1) continue;
        int j=2;
        while(j*i<=M){
            p[j*i]=-1;
            j++;
        }
    }
    for(int i=2;i<=M;i++){
        if(p[i]==0){
            p[i]+=pre;
            pre++;
        }
    }
}

int l,r;

int cal(int x){
    if(x<=1) return 0;
    for(int i=x;i>=2;i--) if(p[i]>0) return p[i];
}

int main(){
    tinh();
    int t;
    cin>>t;
    while(t--){
        cin>>l>>r;
        l--;
        cout<<cal(r)-cal(l)<<endl;
    }
}