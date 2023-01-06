#import<stdio.h>
#include<stdlib.h>
#include<string.h>

int check(char *s){
	int i,j=0,n=strlen(s)/2;
	for(i=0;i<n;i++){
		if(s[i]==s[strlen(s)-1-i]){
			j++;
		}
	}
	if(j==n){
		return 1;
	}
	else{
		return 0;
	}
}

int main(){
    char s[1000];
    scanf("%s",&s);
    if(check(s)==1){
    	printf("Co");
	}
	else{
		printf("Khong");
	}
}
