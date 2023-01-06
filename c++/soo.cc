#include<stdio.h>
#include<math.h>
int main(){
   int n,x=1;
   scanf("%d",&n);
   if(n<2)printf("Khong phai la so nguyen to");
   else{
      for(int i=2;i<=(int)sqrt(n);i++){
         if(n%i==0) x=0;
      }
      if(x==1)printf("La so nguyen to");
      else printf("Khong phai la so nguyen to");
   }
}