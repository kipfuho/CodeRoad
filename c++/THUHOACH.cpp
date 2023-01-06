#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main(){
    int N,C;
    cin>>N>>C;
    int w[N],M[C+1]={0};
    M[0]=1;
    for(int i=0;i<N;i++)cin>>w[i];
    for(int i=0;i<N;i++){
        for(int j=C;j>=w[i];j--){
            if(M[j-w[i]]==1) M[j]=1;
        }
    }
    for(int i=C;i>=0;i--){
        if(M[i]==1){
            cout<<i;
            break;
        }
    }
}