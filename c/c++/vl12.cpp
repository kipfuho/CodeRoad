#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n==0) cout<<"INF";
    else{
        for(int i=abs(n);i>0;i--){
            if(n%i==0) cout<<i<<" ";
        }
    }
}