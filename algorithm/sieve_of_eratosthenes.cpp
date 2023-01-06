//?????
#include<bits/stdc++.h>

using namespace std;

void generate(int p[],int n){
    memset(p,0,n);
    for(int i=2;i<=sqrt(n);i++){
        if(p[i]==1) continue;
        int j=2;
        while(j*i<=n){
            p[j*i]=1;
            j++;
        }
    }
}

int main(){
    int p[100001];
    generate(p,100001);
}