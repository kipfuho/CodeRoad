#include<iostream>
using namespace std;
int main(){
    int n;
    double x;
    cin>>x>>n;
    double s=x,t=x;
    for(int i=2;i<=n;i++){
        t*=(double)x/i;
        s+=t;
    }
    printf("%.2lf",s);
}