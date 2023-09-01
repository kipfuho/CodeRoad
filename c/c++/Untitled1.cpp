#include<stdio.h>
void tang(float *x){
	*x+=1;
}

int main() {
	float x;
	do{scanf("%f",&x);}while(x>(-1)&&x<1);
	tang(&x);
	printf("%f",x);
	return 0;
}

