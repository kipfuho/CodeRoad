#include<stdio.h>
#include <math.h>
float tong(float epsilon,float x);
int main() {
	//dung ham do while de tai su dung chuong trinh
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
	//Nhap x
	do{
		printf("Nhap x: ");
		scanf("%f",&x);}
	while(x<(-1)&&x>1);
	//goi ham` tinh tong ln
	tong(epsilon,x);
	printf("Co muon tiep tuc k, co viet 1\n");
	scanf("%d",&luachon);
	}
	while(luachon==1);
}	
float tong(float epsilon,float x){		
	//tinh tong ln dung for
	float tong=x;
	float add;
	int i;
	for(i=1;i++;){
		add=pow(x,i)/i;
		tong+=pow(-1,i-1)*add;
		if(add<=epsilon){
			break;
		}
	}
	printf("Tong can tim la: ");
	printf("%.5f\n",tong);
};

