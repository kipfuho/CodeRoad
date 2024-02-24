// Nguyễn Đình Út Biu 20215317
// Bài tập 7: Chia tiền

#include <iostream> // Đổi thư viện

using namespace std;

int main(){
    int n;
    cin >> n;
    int sum = 0; // ans không dùng
    while(n--){
        int k, t;
        cin >> k >> t;
        while(k--){
            int a;
            cin >> a;
            if (t == 1) sum += a;
            else if (t == -1) sum -= a; // Thay bằng else if
            // ans = max(ans, -sum); Không cần thiết
        }
    }
    // Nếu sum âm thì số tiền cần mang đi là -sum
    if(sum < 0){cout << -sum};
    else cout << 0;
}
