#include<stdio.h>
#include<math.h>

int min(int arr[],int n){
    int x=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]<x) x=arr[i];
    }
    return x;
}

int ucln1(int arr[],int n){
    int x=1,y=1;
    for(int i=1;i<=min(arr,n);i++){
        for(int j=0;j<n;j++){
            if(arr[j]%i!=0){
                y=0;
                continue;
            }
        }
        if(y==1){
            x=i;
        }
        y=1;
    }
    return x;
}
int ucln2(int x,int y){
    int min=x>y?y:x;
    int z=1;
    for(int i=1;i<=min;i++){
        if(x%i==0&&y%i==0) z=i;
    }
    return z;
}
int main(){
    int R;
    scanf("%d",&R);
    int a[R],b[R];
    for(int i=0;i<R;i++) scanf("%d",&a[i]);
    for(int i=0;i<R;i++) scanf("%d",&b[i]);
    printf("%d",ucln2(ucln1(a,R),ucln1(b,R)));
}