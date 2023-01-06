#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void sort_increase(int *arr,int n){
    int i,j;
    for(i=0;i<n-1;++i){
        for(j=0;j<i+1;++j){
            if(*(arr+i)>*(arr+j)){
                int temp=*(arr+i);
                *(arr+i)=*(arr+j);
                *(arr+j)=temp;
            }
        }
    }
}
int main(){
    int i,*arr;
    arr=(int*)malloc(5*sizeof(int));
    *(arr+0)=5;
    *(arr+1)=4;
    *(arr+2)=3;
    *(arr+3)=2;
    *(arr+4)=1;
    sort_increase(arr,5);
    for(i=0;i<5;++i){
        printf("%d",*(arr+i));
    }
    free(arr);
}