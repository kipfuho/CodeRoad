#include<stdio.h>
#include <stdlib.h>
int main(){
	int i,n,*arr,sum=0;
	scanf("%d",n);
	arr=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;++i){
		scanf("%d",arr+i);
	}
	for(i=1;i<n-1;++i){
		if(*(arr+i)>*(arr+i-1)&&*(arr+i)>*(arr+i+1)){
			sum+=*(arr+i);
		}
	}
	printf("%d",sum);
}
