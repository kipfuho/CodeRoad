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
	printf("%d",factorial(13));
}
