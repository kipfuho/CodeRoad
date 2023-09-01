#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n<=5) cout<<"NO";
    else{
        int s=0;
        for(int i=1;i<=n/2;i++){
            if(n%i==0) s+=i;
        }
        if(s==n) cout<<"YES";
        else cout<<"NO";
    }
}