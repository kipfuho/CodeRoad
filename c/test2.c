#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void y_12(){
	int arr[10]={0,0,0,0,0,0,0,0,0,0};
	int index[10]={0,1,2,3,4,5,6,7,8,9};
	char s[100];
	int i,j,temp1,temp2,m=0;	
	while(m==0){
		scanf("%s",s);
		for(i=0;i<100;i++){			
			int a=s[i]-'0';
			if(s[i]=='\0'){break;}
			if(a<0||a>9){
				m++;
				break;
			}
		}
		if(m!=0){printf("Day so co ki tu khong phai so moi nhap lai.\n");m=0;}
		else{break;}
	}
	for(i=0;i<strlen(s);i++){
		arr[s[i]-'0']++;
	}
	for(i=0;i<10;i++){
		printf("%d ",arr[i]);
	}
	for(i=0;i<9;i++){
		for(j=i+1;j<10;j++){
			if(arr[i]<arr[j]){
				temp1=arr[i];
				temp2=index[i];
				arr[i]=arr[j];
				index[i]=index[j];
				arr[j]=temp1;
				index[j]=temp2;
			}
		}
	}
	printf("Ki tu xuat hien nhieu nhat la: %d\n",index[0]);
	printf("Voi so lan xuat hien la: %d",arr[0]);
}

int main(){
	y_12();
}
	
