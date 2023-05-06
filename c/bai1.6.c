#include<stdio.h>
#include<stdlib.h>

// Hàm đảo ngược dùng chỉ số
void reversearray(int arr[], int size){

    int l = 0, r = size - 1, tmp;

    while(l < r){
        tmp = arr[l];
        arr[l] = arr[r];
        arr[r] = tmp;
        l++;
        r--;
    }

}

// Hàm đảo ngược dùng con trỏ
void ptr_reversearray(int *arr, int size){

    int l = 0, r = size - 1, tmp;

    while(l < r){
        tmp = *(arr+l);
        *(arr+l) = *(arr+r);
        *(arr+r) = tmp;
        l++;
        r--;
    }

}

int main(){
    // Mảng 1 khai báo bình thường
    int size1;
    printf("Nhap so phan tu cho mang 1: ");
    scanf("%d", &size1);
    int arr1[size1];
    printf("Nhap cac phan tu cho mang 1: ");
    for(int i = 0; i < size1; i++){
        scanf("%d", &arr1[i]);
    }
    // Mảng 2 dùng con trỏ
    int size2;
    printf("Nhap so phan tu cho mang 2: ");
    scanf("%d", &size2);
    int* arr2 = (int *) malloc(size2 * sizeof(int));
    printf("Nhap cac phan tu cho mang 2: ");
    for(int i = 0; i < size2; i++){
        scanf("%d", (arr2 + i));
    }
    // Đảo ngược các mảng
    reversearray(arr1, size1);
    ptr_reversearray(arr2, size2);
    // In các mảng sau khi đảo ngược
    printf("Mang 1 sau khi dao nguoc la: ");
    for(int i = 0; i < size1; i++){
        printf("%d ", arr1[i]);
    }
    printf("\nMang 2 sau khi dao nguoc la: ");
    for(int i = 0; i < size2; i++){
        printf("%d ", *(arr2 + i));
    }
    // Giải phóng mảng 2
    free(arr2);
    return 0;
}