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
vector<int> cartesian_tree(1e6);
vector<vector<int>> sparse_table(1e6, vector<int>(20, -1));
vector<int> height(1e6, -1);

// calculate a array represent the sequence in cartesian tree
void preprocess_tree(){
    stack<int> st;
    int k, k_1 = -1;
    for(int i = 0; i < n; i++){
        while(!st.empty() && seq[i] < seq[st.top()]){
            k_1 = st.top();
            st.pop();
        }

        k = st.empty() ? -1 : st.top();
    
        if(k != - 1) cartesian_tree[i] = k;
        if(k < k_1) cartesian_tree[k_1] = i;

        st.push(i);
    }

    while(!st.empty()){
        k_1 = st.top();
        st.pop();
    }
    cartesian_tree[k_1] = -1;
    height[k_1] = 1;
}

// calculate height and sparse_table for query
void preprocess_lca(){
    for(int i = 0; i < n;  i++){
        int u = i, len = 0;
        while(height[u] == -1){
            len++;
            u = cartesian_tree[u];
        }
        height[i] = height[u] + len;
    }

    for(int i = 0; i < n; i++){
        sparse_table[i][0] = cartesian_tree[i];
    }

    for(int j = 1; 1<<j < n; j++){
        for(int i = 0; i < n; i++){
            if(sparse_table[i][j - 1] != -1) sparse_table[i][j] = sparse_table[sparse_table[i][j - 1]][j - 1];
        }
    }
}

inline int rmq(int i, int j){
    if(height[j] > height[i]){
        int temp = i;
        i = j;
        j = temp;
    }

    int log = log2(height[i]);

    for(int k = log; k >= 0; k--){
        if(height[i] - (1<<k) >= height[j]) i = sparse_table[i][k];
    }

    if(i == j) return seq[i];

    for(int k = log; k >= 0; k--){
        if(sparse_table[i][k] != -1 && sparse_table[i][k] != sparse_table[j][k]){
            i = sparse_table[i][k];
            j = sparse_table[j][k];
        }
    }

    return seq[cartesian_tree[i]];
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> seq[i];
    }

    preprocess_tree();
    preprocess_lca();

    cin >> q;
    int res = 0, i, j;
    while(q--){
        cin >> i >> j;
        res += rmq(i, j);
    }
    cout << res;
}