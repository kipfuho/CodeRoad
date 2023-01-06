#include<stdio.h>
#include<math.h>
#include<stdlib.h>
float ptu(float x, int n){
    int i,a;
    if(n%2==0){
        a=1;
    }
    else{
        a=-1;
    }
    float temp=1;
    for(i=1;i<=2*n+1;++i){
        temp=temp*x/i;
    }
    return a*temp;
}
int main(){
    float x,ans=0;
    int i=0;
    scanf("%f",&x);
    while(fabs(ptu(x,i))>0.0001){

        ans+=ptu(x,i);
        i++;

    }

    printf("%f",ans);
}

