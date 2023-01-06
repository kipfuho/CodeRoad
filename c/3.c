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
    int i,n,*a;
    scanf("%d",n);
    for(i=0;i<n;++i){
        scanf("%d",*(a+i));
    }
    sort(&a,n);
    for(i=0;i<n;++i){
        printf("%d",*(a+i));
    }
    free(a);
}