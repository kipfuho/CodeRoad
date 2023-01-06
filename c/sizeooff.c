#include<stdio.h>
#include <stdlib.h>
int main(){
    int n;
    scanf("%d",&n);
        int arr[n];
        for(int i=0;i<n;i++) scanf("%d",&arr[i]);
        int m=arr[0]*arr[1];
        for(int i=0;i<n-2;i++){
            if(abs(arr[i]*arr[i+1])<abs(arr[i+1]*arr[i+2]))m=arr[i+1]*arr[i+2];
        }
        if(m<0||n==1)printf("0");
        else printf("%d",m);
    
}