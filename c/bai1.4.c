// Nguyễn Đình Út Biu - 20215317
/*
Bài tập 1.4. Viết hàm countEven(int*, int) nhận một mảng số nguyên và kích thước của mảng, trả về số lượng số chẵn trong mảng???
*/

#include<stdio.h>
#include<stdlib.h>

int counteven(int* arr, int size){
    int evenCount = 0;
    // Dùng vòng lặp kiểm tra xem các phần tử trong mảng có chẵn hay không, nếu cho thì cộng 1 vào cho biến evenCount
    for(int i = 0; i < size; i++){
        if(arr[i] % 2 == 0) evenCount++;
    }
    return evenCount;
}

int main(){
    printf("Nguyen Dinh Ut Biu - 20215317");
    int size;
    // Nhập số phần tử của mảng
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &size);
    // Thực hiện cấp phát bộ nhớ cho mảng
    int* arr = (int *) malloc(size * sizeof(int));
    // Nhập các phần tử cho mảng
    printf("\nNhap cac phan tu cua mang: ");
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }
    // In ra số phần tử chẵn
    printf("So phan tu chan trong mang la %d", counteven(arr, size));
    // Giải phóng bộ nhớ
    free(arr);
}