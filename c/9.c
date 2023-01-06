#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void sort_increase(int *arr,int n){
    int i,j;
    for(i=0;i<n-1;++i){
        for(j=i+1;j<n;++j){
            if(*(arr+i)>*(arr+j)){
                int temp=*(arr+i);
                *(arr+i)=*(arr+j);
                *(arr+j)=temp;
            }
        }
    }
}

int main(){
    int i,n,*arr;
    scanf("%d", &n);
    for(i=0;i<n;++i){
        int k,t_1=i;
        arr=(int*)malloc(n*sizeof(int));
        for(k=0;k<n;++k){
            *(arr+k)=n-i+t_1;
            if(t_1>0){
                t_1--;
            }
        }
        for(k=0;k<n;++k){
            printf("%d ",*(arr+k));
        }
        sort_increase(arr,n);
        for(k=1;k<n;++k){
            printf("%d ",*(arr+k));
        }
        printf("\n");
        free(arr);
    }
    for(i=n-2;i>=0;--i){
        int k,t_1=i;
        arr=(int*)malloc(n*sizeof(int));
        for(k=0;k<n;++k){
            *(arr+k)=n-i+t_1;
            if(t_1>0){
                t_1--;
            }
        }
        for(k=0;k<n;++k){
            printf("%d ",*(arr+k));
        }
        sort_increase(arr,n);
        for(k=1;k<n;++k){
            printf("%d ",*(arr+k));
        }
        printf("\n");
        free(arr);
    }
}
