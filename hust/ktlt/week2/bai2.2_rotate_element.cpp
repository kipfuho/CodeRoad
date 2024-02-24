// Nguyễn Đình Út Biu - 20215317
/*
Bài tập 2.2. Viết hàm hoán vị vòng tròn 3 biến a, b, c. Sau khi thực hiện hàm, các biến a, b, c tương ứng nhận các giá trị mới b, c, a.
*/


#include <stdio.h>

// Hàm đổi giá trị cho x, y, z
void rotate(int &x, int &y, int &z) {
    int t = x;
    x = y;
    y = z;
    z = t;
}

int main() {
    int x, y, z;
    
    //# Nhập 3 số nguyên
    scanf("%d %d %d", &x, &y, &z);
    
    printf("Before: %d, %d, %d\n", x, y, z);
    rotate(x, y, z);
    printf("After: %d, %d, %d\n", x, y, z);
    
    return 0;
}