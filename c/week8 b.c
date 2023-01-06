#include<stdio.h>
#include <stdlib.h>
#include <stdlib.h>
void sort(int *a,int size){
   int i,j;
   for(i=0;i<size-1;++i){
      for(j=i+1;j<size;++j){
         if(*(a+j)<*(a+i)){
            int temp=*(a+i);
            *(a+i)=*(a+j);
            *(a+j)=temp;
         }
      }
   }
}
void abssort(int *a,int size){
	int i,j;
   	for(i=0;i<size-1;++i){
      for(j=i+1;j<size;++j){
         if(abs(*(a+j))<abs(*(a+i))){
            int temp=*(a+i);
            *(a+i)=*(a+j);
            *(a+j)=temp;
         }
      }
   }
}
int main(){
	int i,n,*arr;
	scanf("%d",&n);
	arr=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;++i){
		scanf("%d",arr+i);
	}
	sort(arr,n);
	for(i=0;i<n;++i){
		printf("%d ",*(arr+i));
	}
	printf("\n");
	for(i=0;i<n;++i){
		printf("%d ",*(arr+n-1-i));
	}
	printf("\n");
	abssort(arr,n);
	for(i=0;i<n;++i){
		printf("%d ",*(arr+n-1-i));
	}
}
