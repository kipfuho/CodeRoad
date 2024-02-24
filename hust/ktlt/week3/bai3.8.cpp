// Nguyen Dinh Ut Biu 20215317
// Bai3.8: Bạn đang muốn kiểm tra xem một vật cho trước có 
// đúng nặng M như người ta nói hay không. Có một cân thăng 
// bằng và n qua cân. Quả thứ i nặng mi. Hãy chi ra mot cach 
// c�n thoa m�n. Quy c�ch in ra d� duoc t�ch hop trong m� nguon duoi.  

#include <bits/stdc++.h>
using namespace std;

// state co 2 truong th�ng tin l� i v� j
// i la so thu tu cua qua nang hien tai, i = 1...n
// j the hien trang thai cua qua nang so voi loi giai:
//    -1: qua nang nam o c�ng c�n M
//	   0: kh�ng d�ng qua nang
//	   1: qua nang nam o kh�c c�n M 
struct state{
    int i, j;
    state(int _i = 0, int _j = 0): i(_i), j(_j) {}
};

int main() {
    int n, M;
    cin >> n >> M;
    int m[n+1];
    for (int i = 1; i <= n; ++i) cin >> m[i];
    int x[n+1];
    stack<state> s;
    //# sum of selected weights
    int sum = 0;
    s.push(state(1, -1));
    while (!s.empty()){
        state &top = s.top();
        // So thu tu dinh stack > n thi xem co phai loi giai khong
        if (top.i > n){
            if (sum == M){
                for (int i = 1; i <= n; ++i){
                    if (x[i] == -1) cout << '-' << m[i];
                    if (x[i] == 1) cout << '+' << m[i];
                }
                cout << "=" << M;
                exit(0);
            }
            s.pop();
            continue;
        }
        
        //# Khu de quy
        // top.j > 1 tuc la da x�t 3 trang thai -1, 0, 1 -> bo khoi stack
        if(top.j > 1){
        	sum -= m[top.i];
        	s.pop();
        	continue;
		}
		// c�n bang lai sum khi chuy�n tu trang thai -1 sang 0
        if(top.j == 0){
        	sum += m[top.i];
		}
        
        // g�n x, sum v� push v�o stack qua nang tiep theo
		x[top.i] = top.j;
		sum += m[top.i]*top.j;
		s.push(state(top.i + 1, -1));
        top.j++;
    }
    cout << -1;

    return 0;
}
