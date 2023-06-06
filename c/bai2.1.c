// Nguyễn Đình Út Biu - 20215317
/*
Bài 2.1. Viết hàm tính độ dài cạnh huyền của tam giác theo độ hai cạnh góc vuông.
*/

#include <stdio.h>
#include <math.h>

// Hàm tính cạnh huyền của tam giác vuông với 2 cạnh góc vuông là x và y
float get_hypotenuse(float x, float y) {
    return sqrt(x*x + y*y);
}

int main(){
    // Lấy input
    float x, y;
    scanf("%f%f", &x, &y);
    // In kết quả
    float z = get_hypotenuse(x, y);
    printf("z = %.2f\n", z);
    
    return 0;
}