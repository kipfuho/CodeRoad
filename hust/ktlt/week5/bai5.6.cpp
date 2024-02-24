// Nguyễn Đình Út Biu 20215317
// Bài tập 6: Tổng kết

#include <iostream> // Đổi thư viện
using namespace std;

int A = 0, B = 0, C = 0, D = 0, F = 0;

void cal(double a){ // Sửa hàm và thứ tự so sánh
    if (8.5 <= a) A++; // CNTT hay được A, mặt khác chỉ tốn 1 phép so sánh
    if (7 <= a && a < 8.5) B++;
    if (5.5 <= a && a < 7) C++;
    if (4 <= a && a < 5.5) D++;
    if (a < 4) F++; // Ít khả năng được F, để cuối
}

int main(){
    int n;
    cin >> n;
    while(n--){
        double a; // Sửa kiểu dữ liệu
        cin >> a;
        cal(a);
        /* Thay vì gọi hàm trả về giá trị rồi so sánh thì trực tiếp cộng luôn
        char b = cal(a);
        if (cal(a) == 'A') ++A;
        if (cal(a) == 'B') ++B;
        if (cal(a) == 'C') ++C;
        if (cal(a) == 'D') ++D;
        if (cal(a) == 'F') ++F;
        */
    }
    cout << A << " " << B << " " << C << " " << D << " " << F;
}
