/*
Cho mảng A[0,N−1]. Bạn cần trả lời Q truy vấn. Mỗi truy vấn gồm 2 số i, j và bạn cần đưa ra vị trí của phần tử 
có giá trị nhỏ nhất trong đoạn từ i đến j của mảng A, ký hiệu là RMQ(i,j).

input:
line 1: n (n <= 10^6)
line 2: a_0...a_n (1 <= a_i <= 10^6)
line 3: q (q <= 10^6)
line 4: i, j
output:
sum(rmq(i, j)) of q queries

Example
Input
16
2 4 6 1 6 8 7 3 3 5 8 9 1 2 6 4
4
1 5
0 9
1 15
6 10

Output
6
*/

#include<bits/stdc++.h>

using namespace std;

int n, q;
vector<int> seq(1e6);
vector<vector<int>> sparse_table(1e6, vector<int>(20, -1));

// calculate sparse table
void preprocess(){
    for(int i = 0; i < n; i++){
        sparse_table[i][0] = i;
    }

    for(int j = 1; 1<<j <= n; j++){
        for(int i = 0; i + (1<<j) - 1 < n; i++){
            if(seq[sparse_table[i][j - 1]] < seq[sparse_table[i + (1<<(j-1))][j - 1]]){
                sparse_table[i][j] = sparse_table[i][j - 1];
            }
            else{
                sparse_table[i][j] = sparse_table[i + (1<<(j-1))][j - 1];
            }
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> seq[i];
    }

    preprocess();

    cin >> q;
    int res = 0, i, j, k;
    while(q--){
        cin >> i >> j;
        k = log2(j - i + 1);
        if(seq[sparse_table[i][k]] <= seq[sparse_table[j - (1<<k) + 1][k]]) res += seq[sparse_table[i][k]];
        else res += seq[sparse_table[j - (1<<k) + 1][k]];
    }
    cout << res;
}