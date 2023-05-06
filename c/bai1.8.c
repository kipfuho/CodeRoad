#include<stdio.h>
#include<stdlib.h>

int main(){
    // khai báo các biến, evenSum là tổng các số chẵn cần tìm
    int m,n, evenSum = 0;
    printf("Enter m, n = ");
    scanf("%d %d", &m, &n);
    // Khai báo và cấp phát bộ nhớ cho ma trận mxn
    int **matrix;
    matrix =(int**) malloc(m*sizeof(int*));
    for(int i = 0; i < m; i++){
        matrix[i] = (int*) malloc(n*sizeof(int));
    }
    // nhập phần tử cho ma trận
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("mt[%d][%d] = ", i, j);
            scanf("%d", &matrix[i][j]);
            if(matrix[i][j] % 2 == 0){
                evenSum += matrix[i][j];
            }
        }
    }
    
    // In ma trận theo các hàng
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // in tổng các số chẵn trong ma trận
    printf("The sum of all even elements is %d", evenSum);

    // giải phóng ma trận
    for(int i = 0; i < m; i++){
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}