// Nguyễn Đình Út Biu 20215317
// Bài tập 2: Tìm và sửa các lỗi cú pháp

#include <iostream>
using namespace std;

int n, M, m[100], v[100];
int x[100], best, sumV, sumM, All[100];

void init(){
    for (int i = n; i >= 1; --i){
        All[i] = All[i+1] + v[i]; // Dùng sai tên biến
    }
}

void print() {
    cout << best;
}

void process(int i){
    if (sumV + All[i] <= best || sumM > M) return ; // Dùng sai tên biến, return int trong hàm void
    if (i > n){
        best = sumV; // Thiếu dấu ;
        return ; // return int trong hàm void
    }
    process(i+1);
    sumM += m[i];
    sumV += v[i];
    process(i+1);
    sumM -= m[i];
    sumV -= v[i];
}

int main() {
    cin >> n >> M;
    for (int i = 1; i <= n; ++i)
        cin >> m[i] >> v[i];
    init();
    process(1);
    print();
    return 0;
}
