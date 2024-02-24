// Nguyễn Đình Út Biu 20215317
// Bài tập 5: Năm nhuận

#include <iostream> // Lược bớt các thư viện thừa thãi
using namespace std;

int main(){
    int n;
    cin >> n;
    // bool found = false; Không cần thiết
    while(n--){
        int a;
        cin >> a;
        if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0)){ // Sửa điều kiện
            cout << "Yes"; // Thông báo luôn
            return 0; // break nếu tìm thấy
        }
    }
    cout << "No";
}
