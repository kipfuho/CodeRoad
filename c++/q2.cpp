#include<iostream>
using namespace std;
int main(){
    int N,X;
    cin>>N>>X;
    if(N<0||X<0){
        cout<<"Loi du lieu";
        return 0;
    }
    if(X<10) cout<<(10-X)*(N-1);
    else cout<<0;
}