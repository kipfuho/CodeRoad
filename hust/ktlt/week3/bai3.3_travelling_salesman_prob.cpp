// Nguyen Dinh Ut Biu 20215317
// Bai 3.3: Mot nguoi xuat phát tai thành pho 1, muon di tham tat ca 
// các thành pho khác, moi thành pho đúng 1 lan và quay ve 1. Chi phí 
// de di tu thành pho i sang thành pho j là c_i_j. Hãy tìm tong chi phí 
// nho nhat có thể.

#include <bits/stdc++.h>
using namespace std;
#define MAX 100  

int n, c[MAX][MAX]; //# số thành pho và ma tran chi phí
int cmin = INT_MAX; //# chi phí di lai nho nhat giua hai thành pho khác nhau
int best = INT_MAX; //# tong chi phí nho nhat can tìm, ban dau dat bang giá tri vô cùng lon INT_MAX = 2^31-1
int curr; //# tong chi phí tai thoi diem hien tai
int mark[MAX]; //# đánh dau nhung thành pho dã di
int x[MAX]; //# luu giu các thành pho đã di

//# đoc du lieu vào
void input(){
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j){
            cin >> c[i][j];
            if (c[i][j] > 0) cmin = min(cmin, c[i][j]);
        }
}

//# Thuat toán quay lui
void TRY(int k){
    for(int i = 2; i <= n; i++){
    	// Kiem tra xem thanh pho dang xet da di chua
        if(mark[i] == 0){
            int chiphi = c[x[k - 1]][i];
            curr += chiphi;
            // Xem xet xem co kha nang nhanh hien tai cho loi giai tot hon loi giai hien tai khong
            if(curr + (n - k + 1)*cmin > best ){
                curr -= chiphi;
                continue;
            }
            // Da di den thanh pho cuoi cung, thuc hien so sanh loi giai moi voi loi giai cu
            if(k == n){
                if(curr + c[i][1] < best) best = curr + c[i][1];
            }
            else{
            	// Danh dau thanh pho hien tai va tiep tuc thanh pho tiep theo
                mark[i] = 1;
                x[k] = i;
                TRY(k + 1);
            }
            // Bo danh dau thanh pho hien tai va thu tiep
            curr -= chiphi;
            mark[i] = 0;
        }
    }
}

int main() {
    input();
    x[1] = 1;
    TRY(2);
    if(n == 1) best = 0;
    cout << best;
    return 0;
}
