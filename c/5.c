#include<stdio.h>
#include<math.h>
#include<stdlib.h>
long factorial(int y){
    if(y==0){
        return 1;
    }
    else if(y>0){
        return(y*factorial(y-1));
}
}
int main(){
	float x,ans=0;
    scanf("%f",x);
    int i=0;
    while(pow(x,2*n+1)/factorial(2*n+1)>pow(10,-4)){
        a=pow(x,2*n+1)/factorial(2*n+1);
        ans+=a;
        i++;
    }
    printf("%f",ans);
}