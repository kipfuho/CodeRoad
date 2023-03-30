#include<stdio.h>
#include<string.h>
int main(){
    char DS[100][30];
    char temp[30];
    int n;
    printf("Nhap so sinh vien (<100): \n");
    scanf("%d",&n);
    fflush(stdin);
    for(int i=0;i<n;i++){
        printf("Nhap ten sinh vien thu %d: ",i+1);
        gets(DS[i]);
        if(strcmp(DS[i],"QQQ\x0")==0) break;
    }
    for(int i=0;i<n;i++){
        if(strcmp(DS[i],"QQQ\x0")==0) break;
        printf("%s\n",DS[i]);
    }
    for(int i=0;i<n-1;i++){
        if(strcmp(DS[i],"QQQ\x0")==0) break;
        for(int j=i+1;j<n;j++){
            if(strcmp(DS[j],"QQQ\x0")==0) break;
            else if(strcmp(DS[i],DS[j])>0){
                strcpy(temp,DS[i]);
                strcpy(DS[i],DS[j]);
                strcpy(DS[j],temp);
            }
        }
    }
    for(int i=0;i<n;i++){
        if(strcmp(DS[i],"QQQ\x0")==0) break;
        printf("%s\n",DS[i]);
    }
    
}