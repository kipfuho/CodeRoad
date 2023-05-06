#include <stdio.h>
int main(){
    int a[7]= {13, -355, 235, 47, 67, 943, 1222}; 
    printf("address of first five elements in memory.\n");
    for (int i=0; i<5;i++)  printf("\ta[%d] ",i);
    printf("\n");
    
    // In địa chỉ của 5 phần tử đầu tiên của mảng a
    for (int i=0; i<5;i++)  printf("\t%p ",&a[i]);
           
    return 0;
}
