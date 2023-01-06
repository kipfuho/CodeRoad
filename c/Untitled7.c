#include<stdio.h>

int main(){
    int i,x,y;
    scanf("%d %d",&x,&y);
    if(x==y){
        printf("%d",x);
    }
    else{
        int ans;
        for(i=1;i<=x;++i){
            if((y*i)%x==0){
                ans=y*i;
                break;
            }
        }
        printf("%d",ans);
    }
}
