#include<stdio.h>

int maxsub(int a[],int n){
    int max=a[0];
    int b[n];b[0]=a[0];
    for(int i=1;i<n;i++){
        b[i]=b[i-1]+a[i];
        if(b[i]>b[i-1])max=b[i];
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)scanf("%d",&a[i]);

}