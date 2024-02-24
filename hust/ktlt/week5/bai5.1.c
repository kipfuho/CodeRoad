// Nguyễn Đình Út Biu 20215317
// Bài tập 1: Tìm và sửa các lỗi cú pháp

#include <stdio.h>

int x[100], mark[100], n;

void print(){
    for (int i = 1; i <= n; ++i) printf("%d ", x[i]);
    printf("\n"); // Dùng sai hàm, sửa từ print() thành printf()
}

void process(int i) {
    if (i > n){
        print(); // Dùng sai hàm
        return;
    }
    for (int j = 1; j <= n; ++j)
        if (!mark[j]){
            mark[j] = 1;
            x[i] = j;
            process(i+1);
            mark[j] = 0;
        }
}

int main() {
    n = 5;
    process(1);
    return 0;
}
