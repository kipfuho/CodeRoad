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
vector<int> segTree(2e6);

// calculate segment tree array
void preprocess(){
    for(int i = 0; i < n; i++){
        segTree[i + n] = seq[i];
    }

    for(int i = n - 1; i > 0; i--){
        segTree[i] = min(segTree[i<<1], segTree[i<<1 | 1]);
    }
    return;
}

inline int rmq(int left, int right){
    left += n;
    right += n;
    int qResult = min(segTree[left], segTree[right - 1]);
    
    for(; left < right; left >>= 1, right >>= 1){
        if(left & 1) qResult = min(qResult, segTree[left++]);
        if(right & 1) qResult = min(qResult, segTree[--right]);
    }
    return qResult;
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> seq[i];
    }

    preprocess();

    cin >> q;
    int res = 0, i, j;
    while(q--){
        cin >> i >> j;
        res += rmq(i, j + 1);
    }
    cout << res;
}