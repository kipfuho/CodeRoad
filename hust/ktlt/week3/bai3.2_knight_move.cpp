// Nguyen Dinh Ut Biu 20215317
// Bai3.2: Trên bàn cờ vua kích thước n×n có một quân mã đang ở ô (1, 1). 
// Hãy đưa ra một dãy các di chuyển của mã sao cho mỗi ô trên bàn cờ đều được 
// đi qua đúng 1 lần (ô (1, 1) được xem là đã đi qua)

#include <iostream>
using namespace std;

int n;
int X[100], Y[100]; //# Lưu toạ độ các bước di chuyển của quân mã
int mark[100][100]; //# Đánh dấu vị trí các ô mà quân mã đã di chuyển qua

//# Mảng hx, hy mô tả 8 vi trí quân mã có thể di chuyển kể từ vị trí hiện tại
const int hx[] = {1, 1, 2, 2, -1, -1, -2, -2}; 
const int hy[] = {2, -2, 1, -1, 2, -2, 1, -1};

//# In ra dãy các di chuyển tìm được
void print_sol(){
    for (int j = 1; j <= n * n; ++j)
        printf("(%d %d)\n", X[j], Y[j]);
    exit(0);
}

//# Thuật toán quay lui
void TRY(int k){
    for(int i = 0; i < 8; i++){
    	// Tinh vi tri quan ma co the nhay den hien tai va kiem tra tinh hop le
        int xx = X[k-1] + hx[i];
        int yy = Y[k-1] + hy[i];
        if(xx < 1 || xx > n) continue;
        if(yy < 1 || yy > n) continue;
        // Nếu hợp lệ, đánh dấu vị trí hiện tại và tiếp tục thử
        if(mark[xx][yy] == 0){
            mark[xx][yy] = 1;
            X[k] = xx; Y[k] = yy;
            // Trong truong hop tim quan ma da nhay het ban co, in ra ket qua va ket thuc thuat toan
            if(k == n*n){
                print_sol();
                return;
            }
            TRY(k + 1);
            // Neu khong tim duoc loi giai, bo danh dau va thu tiep
            mark[xx][yy] = 0;
        }
    }
}

int main(){
    cin >> n;
    mark[1][1] = 1;
    X[1] = Y[1] = 1;
    TRY(2);
    return 0;
}
