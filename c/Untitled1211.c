#include<iostream>
using namespace std;
int main(){
    int T,N,j,s;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>N;
        for(int j=1;;j++){
            s=j*(j+1)/2;
            if(s>N){
                cout<<0<<endl;
                break;
            }
            else if(s==N){
                cout<<1<<endl;
                break;
            }
        }
    }
}
