#include<stdio.h>
#include <math.h>

int main() {
	int luachon;
	do{
	luachon=0;
	float epsilon;
	float x;
	//nhap sai so
    do {
	printf("Nhap epsilon: ");
	scanf("%f",&epsilon);
	} while(epsilon<0);
	
	do{printf("Nhap x: ");;scanf("%f",&x);}while(x<(-1)&&x>1);
	
	//tinh tong ln dung do while
	float tong=x;
	int i=2; 
	do{tong+=(pow(-1,i-1)*pow(x,i))/i;i++;}while(fabs(tong-log(1+x))>=epsilon);
	printf("%.5f\n",tong);
	printf("co muon tiep tuc k, neu co viet 1\n");
	scanf("%d",&luachon);
}while(luachon==1);
}

