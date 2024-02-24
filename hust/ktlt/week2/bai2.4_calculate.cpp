// Nguyễn Đình Út Biu - 20215317
/*
Bài 2.4. Viết các hàm tính lập phương của số nguyên và số thực.
*/


#include <stdio.h>

// Hàm tính lập phương của một số kiểu int
int cube(int x) {
    // Trả về lập phương của x
    return x*x*x;
}

// Hàm tính lập phương của một số kiểu double
double cube(double x) {
    // Trả về lập phương của x
    return x*x*x;
}

int main() {
    int n;
    double f;
    scanf("%d %lf", &n, &f);
    
    printf("Int: %d\n", cube(n));
    printf("Double: %.2lf\n", cube(f));
    
    return 0;
}