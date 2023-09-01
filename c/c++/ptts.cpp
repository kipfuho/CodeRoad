#include<iostream>
#include<math.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    int a=0,b=0;
    while(n%2==0){
        a++;
        b++;
        n=n/2;
    }
    if(a!=0)cout<<"2 "<<a<<endl;
    for(int i=3;i<=1000000;i+=2){
        a=0;
        while(n%i==0){
            a++;
            b++;
            n=n/i;
        }
        if(a!=0)cout<<i<<" "<<a<<endl;
    }
    if(n>2){
        if (sqrt(n)-(long long)sqrt(n)==0) cout<<(long long)sqrt(n)<<" 2";
        else cout<<n<<" 1";
    }
}