#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
        int i;
        char *arr;
        arr=(char*)malloc(5*sizeof(char));
        *(arr+2)='a';
        *(arr+2)='b';
        *(arr+3)='c';
        if(*(arr+0)!=(char)45){
                if((int)*(arr+0)<97&&(int)*(arr+0)>122){
                *(arr+0)='-';
                }
        }
        for(i=0;i<5;++i){
        printf("%c ",*(arr+i));
    
        }
        printf("%d",(int)*(arr+0));
        free(arr);
}