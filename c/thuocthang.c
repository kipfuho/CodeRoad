#include<stdio.h>
#include<string.h>
struct thuoc{
    char ten[25];
    int hsd;
    int sl;
    int gia;
}thuoc[1000];
int main(){
    int n=0;
    char ten[25];
    while(0==0){
        printf("nhap ten thuoc ");
        fflush(stdin);
        gets(ten);
        if(strcmp(ten,"***\0")==0)break;
        else{
            strcpy(thuoc[n].ten,ten);
            printf("\nnhap han su dung "); scanf("%d",&thuoc[n].hsd);
            printf("\nnhap so luong "); scanf("%d",&thuoc[n].sl);
            printf("\nnhap don gia "); scanf("%d",&thuoc[n].gia);
            n++;
        }
    }
    printf("\nDanh sach thuoc:\n");
    for(int i=0;i<n;i++){
        printf("%s\n",thuoc[i].ten);
    }
    int m=0; struct thuoc temp;
    printf("\nDanh sach thuoc da het han:\n");
    for(int i=0;i<n;i++){
        if(thuoc[i].hsd<=2022){
            printf("%s\n",thuoc[i].ten);
            temp=thuoc[i];
            thuoc[i]=thuoc[m];
            thuoc[m]=temp;
            m++;
        }
    }
    printf("\nDanh sach thuoc moi:\n");
    for(int i=m;i<n;i++){
        printf("%s\n",thuoc[i].ten);
    }
    long long tien=0;
    for(int i=0;i<m;i++){
        tien+=(thuoc[i].sl*thuoc[i].gia);
    }
    printf("\nGia tri thuoc het han: %ld\n",tien);
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(thuoc[j].hsd<thuoc[i].hsd){
                temp=thuoc[i];
                thuoc[i]=thuoc[j];
                thuoc[j]=temp;
            }
        }
    }
    printf("\nDanh sach thuoc theo han su dung:\n");
    for(int i=0;i<n;i++){
        printf("%s\n",thuoc[i].ten);
    }
}