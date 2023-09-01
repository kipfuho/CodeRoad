#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int a,b,c,d;
    cin>>a>>b;
    if(abs(a)>abs(b)){
        c=abs(a);
        d=abs(b);
        for(int i=d;i>0;i--) if(c%i==0&&d%i==0) {cout<<i;return 0;}
        cout<<c;
    }
    else{
        c=abs(b);
        d=abs(a);
        for(int i=d;i>0;i--) if(c%i==0&&d%i==0) {cout<<i;return 0;}
        cout<<c;
    }
}