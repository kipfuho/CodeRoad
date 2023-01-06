#include<iostream>
#include<math.h>
#define M 9699690
using namespace std;
int main(){
    int kt[M+1]={0};
    int p[8]={2,3,5,7,11,13,17,19};
    for(int i=0;i<8;i++){
        int j=2;
        while(j*p[i]<=M){
            kt[j*p[i]]=1;
            j++;
        }
    }
    int s=0;
    for(int i=1;i<=M;i++)if(kt[i]==0)s++;
    cout<<s;
}