#include<stdio.h>
int main(){
    long long int n;
    long long int sum=1;
    printf("Nhap so nguyênn:");
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        sum=sum*i;}
    printf("%lld",sum);
	}