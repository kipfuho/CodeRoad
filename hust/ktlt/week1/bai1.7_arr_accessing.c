// Nguyễn Đình Út Biu - 20215317
/*
Bài tập 1.7. Viết chương trình nhập vào một mảng các số nguyên với số lượng các phần tử nhập từ bàn phím. Sau đó sắp xếp mảng theo thứ tự tăng dần. Hiển thị danh sách mảng trước và sau khi sắp xếp.
Yêu cầu chỉ sử dụng con trỏ để truy cập mảng, không truy cập theo index mảng.
*/

#include<stdio.h>
#include<stdlib.h>

// Hàm sắp xếp dùng thuật toán sắp xếp chọn
void sortArr(int* arr, int size){
    for(int i = 0; i < size - 1; i++){
        int index = i;
        for(int j = i + 1; j < size; j++){
            if(*(arr + j) < *(arr + index)){
                index = j;
            }
        }
        if(index != i){
            int tmp = *(arr + i);
            *(arr + i) = *(arr + index);
            *(arr + index) = tmp;
        }
    }
}

int main(){
    printf("Nguyen Dinh Ut Biu - 20215317");
    // Khai báo mảng
    int size, *arr;
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    // Cấp phát bộ nhớ cho mảng
    arr = (int*) malloc(size*sizeof(int));
    for(int i = 0; i < size; i++){
        scanf("%d", (arr + i));
    }

    // mảng trước khi sắp xếp
    printf("The input array is:\n");
    for(int i = 0; i < size; i++){
        printf("%d ", *(arr + i));
    }

    // sắp xếp mảng
    sortArr(arr, size);

    // mảng sau khi sắp xếp
    printf("\nThe sorted array is:\n");
    for(int i = 0; i < size; i++){
        printf("%d ", *(arr + i));
    }

    // giải phóng
    free(arr);
    return 0;
}