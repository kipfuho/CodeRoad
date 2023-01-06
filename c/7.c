#include<stdio.h>
unsigned long long factorial(int x){
    int i;
    unsigned long long a=1;
    for(i=1;i<=x;++i){
        a*=i;
    }
    return a;
}
int main(){
    printf("%llu",factorial(20));
}