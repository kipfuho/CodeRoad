#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void fill(char *arr,int n){
    int i,size=n*4-3;
    for(i=0;i<size;++i){
        if(*(arr+i)!=(char)45){
            *(arr+i)='-';
        }
    }
}

void call_rangoli(int n ){
    int i,j;
    char *arr;
    int size=4*n-3;
    int center=(size-1)/2;
    for(i=0;i<n;++i){
        arr=(char*)malloc(size*sizeof(char));
        fill(arr,n);
        for(j=0;j<=i;++j){
            *(arr+center-j*2)=(char)(97+i-j);
            
        }
        *(arr+center+1)=(char)45;
        for(j=0;j<=i;++j){
            *(arr+center+j*2)=(char)(97+i-j);
            
        }
        
        for(j=0;j<size;++j){
            printf("%c",*(arr+j));
        }
        printf("\n");
        free(arr);
    }
    for(i=n-2;i>=0;--i){
        arr=(char*)malloc(size*sizeof(char));
        fill(arr,n);
        for(j=0;j<=i;++j){
            *(arr+center-j*2)=(char)(97+i-j);
            
        }
        *(arr+center+1)=(char)45;
        for(j=0;j<=i;++j){
            *(arr+center+j*2)=(char)(97+i-j);
            
        }
        
        for(j=0;j<size;++j){
            printf("%c",*(arr+j));
        }
        printf("\n");
        free(arr);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    call_rangoli(n);
}