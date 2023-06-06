// Nguyễn Đình Út Biu - 20215317
/*
Bài tập 1.2. Viết chương trình in ra địa chỉ của 5 phần tử đầu tiên trong mảng 
được định nghĩa sau đây: int a[7]= {13, -355, 235, 47, 67, 943, 1222};
*/


#include <stdio.h>
int main(){
    printf("Nguyen Dinh Ut Biu - 20215317\n");

    int a[7]= {13, -355, 235, 47, 67, 943, 1222}; 
    printf("Address of first five elements in memory.\n");
    for (int i=0; i<5;i++)  printf("\ta[%d]              ",i);
    printf("\n");
    
    // In địa chỉ của 5 phần tử đầu tiên của mảng a
    for (int i=0; i<5;i++)  printf("\t%p ",&a[i]);
           
    return 0;
}
