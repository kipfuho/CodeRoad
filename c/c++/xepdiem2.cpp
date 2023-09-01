#include<bits/stdc++.h>
#include<algorithm>
#define ll long long
#define FOR(i,l,r) for(int i=l;i<r;i++)
using namespace std;

ll l,r;

int number[10]={6,2,5,5,4,5,6,3,7,6};

int count(ll x){
    int retr=0;
    while(x>0){
        retr+=number[x%10];
        x/=10;
    }
    return retr;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int max=0,min=10000000;
        cin>>l>>r;
        for(ll i=l; i<=r;i++){
            int k=count(i);
            if(k>max) max=k;
            if(k<min) min=k;
        }
        cout<<min<<" "<<max<<endl;
    }
}