#include<stdio.h>
#include<stdlib.h>

// Hàm sắp xếp dùng sắp xếp chọn
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