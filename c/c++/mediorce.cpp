#include<iostream>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int m=2*k;
    if(k==0){
        for(int i=1;i<=n;i++){
            cout<<i<<" ";
        }
        return 0;
    }
    if(k==1&&n>2) { cout<<-1; return 0; }
    if(n%m!=0) cout<<-1;
    else{
        int p=n/m;
        for(int i=0;i<p;i++){
            for(int j=1;j<=k;j++){
                cout<<(2*i+1)*k+j<<" ";
            }
            for(int j=1;j<=k;j++){
                cout<<(2*i)*k+j<<" ";
            }
        }
    }
}