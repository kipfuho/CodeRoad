#include<stdio.h>
#include<string.h>
int main(){
    char a[100],c[100];
    int b=0,j=0;
    fgets(a,100,stdin);
    for(int i=0;i<strlen(a);i++) if(a[i]>='0'&&a[i]<=9+'0') b++; else{c[j]=a[i];j++;}
    printf("%d\n",b);
    for(int i=0;i<j;i++)printf("%c",c[i]);
}