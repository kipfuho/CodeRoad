#include<stdio.h>
int main(){
    int a=0,b=0,c=0;
    for(int i=1;i<=1000;i++){
        if(i%6==0&&i%9==0)c++;
        else if(i%6==0)a++;
        else if(i%9==0)b++;
    }
    printf("%d %d %d",a+c,b+c,c);
}