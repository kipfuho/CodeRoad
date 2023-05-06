#include <stdio.h>

int main() {

    int x, y, z;

    int *ptr;

    scanf("%d %d %d", &x, &y, &z);

    printf("Here are the values of x, y, and z:\n");

    printf("%d %d %d\n", x, y, z);

    // trỏ tới x và thực hiện cộng vào kết quả tham chiếu ngược
    ptr = &x;
    *ptr += 100;

    // trỏ tới y và thực hiện cộng vào kết quả tham chiếu ngược
    ptr = &y;
    *ptr += 100;
    
    // trỏ tới z và thực hiện cộng vào kết quả tham chiếu ngược
    ptr = &z;
    *ptr += 100;

    printf("Once again, here are the values of x, y, and z:\n");

    printf("%d %d %d\n", x, y, z);

    return 0;

}   

