#include<stdio.h>
#include<string.h>

void foo(char s2[16], char s1[8]){
	strcpy(s2, "KTLT la mon hoc rat thu vi voi chung ta!");
	puts(s1);
}

int main(){
	char s1[8], s2[16];
	foo(s1, s2);
}
