#include<stdio.h>
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
int main(){
	int n,*arr1,*arr2;
   	int i,j,k=0;
   //Input so n
	scanf("%d",&n);
	arr1 = (int*) malloc(n * sizeof(int));
   	arr2 = (int*) malloc(n * sizeof(int));
   //Input 2 day~ so
	for(i=0;i<n;++i){
		scanf("%d",arr1+i);
      	
	}
	for(j=0;j<n;++j){
		scanf("%d",arr2+j);
     
	}
	
   //so sanh 2 day
  
      sort(arr1,n);
      sort(arr2,n);
      for(i=0;i<n;++i){
         if(*(arr1+i)==*(arr2+i)){
            k++;
         }
      }
   
   if(k==n){
      printf("Co");
   }
   else{
   	printf("Khong");
   }
   //Free memory 2 day
	free(arr1);
	free(arr2);
}
