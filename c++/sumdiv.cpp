#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int t,n,x,y,j;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        x=1;
        j=1;
        while(n%2==0){
            x+=pow(2,j);
            n/=2;
            j++;
        }
        y=x;
        for(int k=3;k<=sqrt(n);k+=2){
            j=1;
            x=1;
            while(n%k==0){
                x+=pow(k,j);
                n/=k;
                j++;
            }
            y*=x;
        }
        if(n>1){
            x=n+1;
            y*=x;
        }
        cout<<y<<endl;
    }
}