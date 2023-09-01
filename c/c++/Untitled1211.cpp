#include<iostream>
using namespace std;
int T,N;
long long a,s;

int main(){

    cin>>T;
    for(int i=0;i<T;i++){
        cin>>N;
        for(int j=1;j<=N;j++){
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
