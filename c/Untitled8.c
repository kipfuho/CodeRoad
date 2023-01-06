#include <stdio.h>

int main() {
	int i,j;
	int n, k;
  	int t1=0,t2=0,t3=0;
    scanf("%d %d", &n, &k);
    for(i=1;i<n;i++){
        for(j=i+1;j<=n;j++){
		
            printf("%d %d\n",i,j);
            if((i&j)<k&&(i&j)>t1){
                t1=(i&j);
            }
            printf("or: %d\n",(i|j));
            if((i^j)<k&&(i^j)>t3){
                t3=(i^j);
            }
        }
    }
    printf("%d %d %d",t1,t2,t3);
}

