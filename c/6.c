#include<stdio.h>
int min(int x,int y){
    return x<y?x:y;
}
int main(){
    int i,x,y;
    scanf("%d %d",x,y);
    if(x==y){
        printf("%d",x);
    }
    else{
        int ans;
        for(i=1;i<min(x,y);++i){
            if(x%i==0&&y%i==0){
                ans=i;
            }
        }
        print("%d",ans);
    }
}