// Nguyễn Đình Út Biu - 20215317
/*
Bài tập 1.3. Viết chương trình yêu cầu nhập giá trị cho 3 biến số nguyên x, y, z kiểu int. Sau đó sử dụng duy nhất một con trỏ để cộng giá trị của mỗi biến thêm 100.
*/


#include <stdio.h>

int main() {
    printf("Nguyen Dinh Ut Biu - 20215317");

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

