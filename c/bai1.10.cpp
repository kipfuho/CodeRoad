// Nguyễn Đình Út Biu - 20215317
/*
Bài tập 1.10: Viết chương trình nhập vào 2 ma trận vuông cùng kích thước n*n, trong đó n nhập từ bàn phím. Sau đó tính tổng và tích của hai ma trận đó và đưa kết quả ra màn hình.
Yêu cầu sử dụng cấp phát động để cấp phát bộ nhớ cho các ma trận.
*/

#include<iostream>

using namespace std;

int n;

void allocate_mem(int** &mt){
    mt = new int*[n];
    for(int i = 0; i < n; i++){
        mt[i] = new int[n];
    }
}

void delete_mem(int** mt){
    for(int i = 0; i < n; i++){
        delete(mt[i]);
    }
    delete(mt);
}

void input(int** mt){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> mt[i][j];
        }
    }
}

void output(int** mt){
    cout << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << mt[i][j] << " ";
        }
        cout << endl;
    }
}

// Tính tổng 2 ma trận
void tongmt(int** mt1, int** mt2, int** mt3){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            mt3[i][j] = mt1[i][j] + mt2[i][j];
        }
    }
}

// Tính tích ma trận mt1 x mt2
void tichmt(int** mt1, int** mt2, int** mt3){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            mt3[i][j] = 0;
            for(int k = 0; k < n; k++){
                mt3[i][j] += mt1[i][k] * mt2[k][j];
            }
        }
    }
}

int main(){
    cin >> n;
    // Khởi tạo 3 ma trận: mt1, mt2 là 2 ma trận nhận input, mt3 là ma trận tạm thời dùng để lưu kết quả tổng và tích 2 ma trận kia
    int **mt1, **mt2, **mt3;
    allocate_mem(mt1);
    allocate_mem(mt2);
    allocate_mem(mt3);
    // Input
    input(mt1);
    input(mt2);
    // Tính tổng 2 ma trận
    tongmt(mt1, mt2, mt3);
    output(mt3);
    // Tính tích 2 ma trận
    tichmt(mt1, mt2, mt3);
    output(mt3);
    // Giải phóng bộ nhớ
    delete_mem(mt1);
    delete_mem(mt2);
    delete_mem(mt3);
}