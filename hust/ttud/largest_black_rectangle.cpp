/*
Problem: Largest black subrectangle
Description
Một hình chữ nhật kích thước n x m được chia thành các ô vuông con 1 x 1 với 2 màu đen hoặc trắng. Hình chữ nhật được biểu diễn bởi ma trận A(n x m) trong đó A(i, j) = 1 có nghĩa ô hàng i, cột j là ô đen và A(i, j) = 0 có nghĩa ô vuông hàng i cột j là ô trắng.
Hãy xác định hình chữ nhật con của bảng đã cho bao gồm toàn ô đen và có diện tích lớn nhất.
Dữ liệu
· Dòng 1: chứa số nguyên dương n và m (1 <= n,m <= 1000)
· Dòng i+1 (i = 1,…, n): chứa hàng thứ i của ma trận A
Kết quả
· Ghi ra diện tích của hình chữ nhật lớn nhất tìm được
Ví dụ
Dữ liệu
4 4
0 1 1 1
1 1 1 0
1 1 0 0
1 1 1 0
Kết quả
6
*/

#include<bits/stdc++.h>

using namespace std;

int n, m;
int arr[1001][1001];

int sol(int index){
    stack<int> st;
    int subArea = 0;
    int i = 0;
    while(i < m){
        if(st.empty() || arr[index][i] >= arr[index][st.top()]){
            st.push(i++);
        }
        else{
            int height = arr[index][st.top()];
            st.pop();

            subArea = max(subArea, height*(st.empty() ? i : i - st.top() - 1));
        }
    }
    while(!st.empty()){
        int height = arr[index][st.top()];
        st.pop();

        subArea = max(subArea, height*(st.empty() ? i : i - st.top() - 1));
    }
    return subArea;
}

void update(int index){
    if(index == n) return;
    for(int i = 0; i < m; i++){
        if(arr[index][i] == 1) arr[index][i] += arr[index - 1][i];
    }
    return;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    int res = 0;
    for(int i = 0; i < n; i++){
        res = max(res, sol(i));
        update(i+1);
    }

    cout << res;
}