/*
Description
Một mê cung hình chữ nhật được biểu diễn bởi 0-1 ma trận NxM trong đó A[i,j] = 1 thể hiện ô (i,j) là tường gạch và A[i,j] = 0 thể hiện ô (i,j) là ô trống, có thể di chuyển vào. Từ 1 ô trống, ta có thể di chuyển sang 1 trong 4 ô lân cận (lên trên, xuống dưới, sang trái, sang phải) nếu ô đó là ô trống. Xuất phát từ 1 ô trống trong mê cung, hãy tìm đường ngắn nhất thoát ra khỏi mê cung.

Input
Dòng 1: ghi 4 số nguyên dương n, m, r, c trong đó n và m tương ứng là số hàng và cột của ma trận A (1 <= n,m <= 999) và r, c tương ứng là chỉ số hàng, cột của ô xuất phát.
Dòng i+1 (i=1,...,n): ghi dòng thứ i của ma trận A

Output
Ghi giá số bước cần di chuyển ngắn nhất để thoát ra khỏi mê cung, hoặc ghi giá trị -1 nếu không tìm thấy đường đi nào thoát ra khỏi mê cung.

Ví dụ
Input
8 12 5 6
1 1 0 0 0 0 1 0 0 0 0 1
1 0 0 0 1 1 0 1 0 0 1 1
0 0 1 0 0 0 0 0 0 0 0 0
1 0 0 0 0 0 1 0 0 1 0 1
1 0 0 1 0 0 0 0 0 1 0 0
1 0 1 0 1 0 0 0 1 0 1 0
0 0 0 0 1 0 1 0 0 0 0 0
1 0 1 1 0 1 1 1 0 1 0 1

Output
7
*/

#include<bits/stdc++.h>

using namespace std;

struct node{
    pair<int, int> pos;
    int length;
    node(pair<int, int> a, int b){
        pos = a;
        length = b;
    }
};

int n, m, r, c;
int maze[1001][1001];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int breadthFirstSearch(pair<int, int> startNode) {
    int visited[1000][1000];
    for(int i = 0; i < 1000; i++){
        for(int j = 0; j < 1000; j++) visited[i][j] = 0;
    }

    queue<node> q;

    visited[startNode.first][startNode.second] = 1;
    node cur = node(startNode, 0);
    q.push(cur);

    while (!q.empty()) {
        cur = q.front();
        q.pop();
        int x = cur.pos.first, y = cur.pos.second, len = cur.length;
        if(x == 0 || x == n - 1 || y == 0 || y == m - 1){
            return len + 1;
        }
        for(int i = 0; i < 4; i++){
            int X = x + dx[i], Y = y + dy[i];
            if((X >= 0) && (X < n) && (Y >= 0) && (Y < m)){
                if((maze[X][Y] == 0) && (visited[X][Y] == 0)){
                    visited[X][Y] = 1;
                    q.push(node({X, Y}, len + 1));
                }
                
            }
        }
    }

    return -1;
}

int main(){
    cin >> n >> m >> r >> c;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> maze[i][j];
        }
    }

    cout << breadthFirstSearch({r-1, c-1});
}