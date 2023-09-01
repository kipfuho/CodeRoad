// Nguyễn Đình Út Biu 20215317
// Lời giải cho bài TSM đột biến

#include <bits/stdc++.h>
using namespace std;
#define MAX 100

int n, m, c[MAX][MAX]; //# số thành phố, cạnh và ma trận chi phí
int cmin = INT_MAX; //# chi phí đi lại nhỏ nhất giữa hai thành phố khác nhau
int best = INT_MAX; //# tổng chi phí nhỏ nhất cần tìm, đặt giá trị đầu = INT_MAX
int curr; //# tổng chi phí tại thời điểm hiện tại
int mark[MAX]; //# đánh dấu những thành phố đã đi
int x[MAX]; //# lưu giữ những thành phố đã đi qua

//# Đọc input
void input(){
    for(int i = 1; i < MAX; i++){
        for(int j = 1; j < MAX; j++) c[i][j] = 0;
    }
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        c[u][v] = w;
        if (c[u][v] > 0) cmin = min(cmin, c[u][v]);
    }
}

//# Thuật toán quay lui
void TRY(int k){
    for(int i = 2; i <= n; i++){
    	// Kiểm tra xem thành phố này đã đi chưa
        if(mark[i] == 0){
            int chiphi = c[x[k - 1]][i];
            if(chiphi == 0) continue;
            else{
                curr += chiphi;
                // Xem xét có khả năng có lời giải tốt hơn không
                if(curr + (n - k + 1)*cmin > best ){
                    curr -= chiphi;
                    continue;
                }
                // Đã đi hết các thành phố, so sánh lời giải
                if(k == n){
                    // Nếu tồn tại đường đi tới thành phố 1
                    if(c[i][1] == 0){
                        curr -= chiphi;
                        continue;
                    }
                    else if(curr + c[i][1] < best) best = curr + c[i][1];
                }
                else{
                    // Đánh dấu và tiếp tục
                    mark[i] = 1;
                    x[k] = i;
                    TRY(k + 1);
                }
                // Bỏ đánh dấu, thử lại
                curr -= chiphi;
                mark[i] = 0;
            }
        }
    }
}

int main(int argc, char** argv) {
    freopen("TSM.inp", "r", stdin);
    freopen("sol3.out", "w", stdout);
    input();
    x[1] = 1;
    TRY(2);
    if(n == 1) best = 0;
    cout << best << endl;
    return 0;
}
