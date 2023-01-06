#include<stdio.h>
#include<math.h>
#include<stdlib.h>
long long factorial(int y){
    if(y==0){
        return 1;
    }
    else if(y>0){
    	int i;
    	long long res=1;
    	for(i=1;i<=y;++i){
    		res=res*i;
		}
        return res;
}
}
int main(){
	float x,a,ans=0;
    scanf("%f",&x);
    int i=0;
    while(pow(x,2*i+1)/factorial(2*i+1)>pow(10,-4)){
        a=pow(x,2*i+1)/factorial(2*i+1);
        printf("%f\n",a);
        ans+=pow(-1,i)*a;
        i++;
    }
    printf("dap an: ");
    printf("%f",ans);
}
