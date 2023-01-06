#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

void set0(int arr[]){
    for(int l=0;l<100;l++) arr[l]=0;
}

void sort_decrease(int arr[]){
    int temp;
    for(int n=0;n<99;n++){
        for(int b=n+1;b<100;b++){
            if(arr[b]>arr[n]){
                temp=arr[b];
                arr[b]=arr[n];
                arr[n]=temp;
            }
        }
    }
}

int main(){
    int t,arr[100];
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        char s[100];
        int pre=0,j=0;
        set0(arr);
        scanf("%s",s);
        for(int m=strlen(s)-1;m>=0;m--){
            if(isdigit(s[m])){
                arr[pre]+=(s[m]-'0')*pow(10,j);
                j++;
            }
            else{
                pre++;
                j=0;
            }
        }
        sort_decrease(arr);
        printf("%d\n",arr[0]);
        if(arr[1]>0)printf("%d\n",arr[1]);
        else printf("-1\n");
    }
}