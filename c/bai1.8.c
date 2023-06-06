// Nguyễn Đình Út Biu - 20215317
/*
Bài tập 1.7. Viết chương trình nhập vào một ma trận 2 chiều kích thước m*n với m và n nhập từ bàn phím. Sau đó đưa ra tổng các phần tử chẵn của ma trận đó.
*/

#include<stdio.h>
#include<stdlib.h>

void allocate_mem(int ***mt, int m, int n){
    //#Allocate memory for the matrix
    
    *mt = (int **) malloc(m * sizeof(int *));
    for(int i = 0; i < m; i++){
        (*mt)[i] = (int *) malloc(n * sizeof(int));
    }
}

void input(int **mt, int m, int n){
    //#Input elements of the matrix
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("mt[%d][%d] = ", i, j);
            scanf("%d", &mt[i][j]);
        }
    }
}

void output(int **mt, int m, int n){
    //# Print all elements of the matrix
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", mt[i][j]);
        }
        printf("\n");
    }
}

int process(int **mt, int m, int n){
    int tong = 0;
    //# Calculate the sum of all even elements in the matrix
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(mt[i][j] % 2 == 0){
                tong += mt[i][j];
            }
        }
    }
    
    return tong;
}

void free_mem(int **mt, int m, int n){
    //# Free memory
    
    for(int i = 0; i < m; i++){
        free(mt[i]);
    }
    free(mt);
}

int main(){
    printf("Nguyen Dinh Ut Biu - 20215317\n");
    int m, n, **mt;
    printf("Enter m, n = ");
    scanf("%d%d", &m, &n);
    allocate_mem(&mt, m, n);
    input(mt, m, n);
    output(mt, m, n);
    printf("The sum of all even elements is %d", process(mt, m, n));
    free_mem(mt, m, n);
    return 0;
}
