// Nguyễn Đình Út Biu - 20215317
/*
Bài tập 1.5. Viết hàm trả về con trỏ trỏ tới giá trị lớn nhất của một mảng các số double. Nếu mảng rỗng hãy trả về NULL.
*/

#include<stdio.h>
#include<stdlib.h>

double* maximum(double* a, int size){

    double *max;

    max = a;

    // Nếu mảng rỗng hoặc số phần tử bằng không return null
    if (a==NULL || size == 0) return NULL;

    // Dùng vòng lặp cùng so sánh để tìm số lớn nhất, sau đó gán địa chỉ của phần tử đó cho max
    for(int i = 0; i < size; i++){
        if(a[i] > *max){
            max = &a[i];
        }
    }
    
    return max;

}

int main(){
    printf("Nguyen Dinh Ut Biu - 20215317\n");
    // Khai báo mảng số thực
    int size;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &size);
    double* arr = malloc(size * sizeof(double));
    printf("Nhap cac phan tu cua mang: ");
    for(int i = 0; i < size; i++){
        scanf("%lf", &arr[i]);
    }

    // In ra phần tử lớn nhất của mảng
    if(maximum(arr, size) != NULL){
        printf("Phan tu lon nhat cua mang la %.5lf", *maximum(arr, size));
    }
    // giải phóng bộ nhớ
    free(arr);
    return 0;
}