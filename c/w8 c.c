#include<stdio.h>
#include <stdlib.h>
int main(){
	int i,n,*arr;
	scanf("%d",&n);
	arr=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;++i){
		scanf("%d",arr+i);
	}
	for(i=0;i<n;++i){
		if(*(arr+i)<0){
			printf("%d ",*(arr+i));
		}
	}
	printf("\n");
	for(i=0;i<n;++i){
		if(*(arr+i)>0){
			printf("%d ",*(arr+i));
		}
	}
}
