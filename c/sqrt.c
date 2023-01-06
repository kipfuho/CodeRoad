#include<stdio.h>
#include<math.h>
int main(){
    long long fact=1;
    int n;
    double x,s=1;
    scanf("%lf %d",&x,&n);
    for(int i=1;i<=n;i++){
        fact=fact*(2*i-1)*2*i;
        s+=pow(x,2*i)/fact;
    }
    printf("%lf",s);
}