// https://codeforces.com/contest/487/problem/B

#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, s, l;
    vector<int> arr(1e5);
    vector<pair<int, int>> tree(2e5); // {minVal, maxVal}

    cin >> n >> s >> l;
    for(int i = 0; i < n; i++) cin >> arr[i];

    // segment tree
    for(int i = 0; i < n; i++){
        tree[i + n] = {arr[i], arr[i]};
    }
    for(int i = n - 1; i > 0; i++){
        tree[i] = {min(tree[i<<1].first, tree[i<<1 | 1].second), max(tree[i<<1].first, tree[i<<1 | 1].second)};
    }

    // rmq for [left; right)
    auto rmq = [&](int left, int right){
        left += n;
        right += n;
        pair<int, int> qResult;
        qResult.first = min(tree[left].first, tree[right - 1].first);
        qResult.second = max(tree[left].second, tree[right - 1].second);
        
        for(; left < right; left >>= 1, right >>= 1){
            if(left & 1){
                qResult.first = min(qResult.first, tree[left++].first);
                qResult.second = max(qResult.second, tree[left++].second);
            }
            if(right & 1){
                qResult.first = min(qResult.first, tree[--right].first);
                qResult.second = max(qResult.second, tree[--right].second);
            }
        }
        return qResult;
    };

    if(l > n){
        cout << -1;
        return 0;
    }

    pair<int, int> firstStrip = rmq(0, l);
    if(firstStrip.second - firstStrip.first > s){
        cout << - 1;
        return 0;
    }

    stack<int> st;
    st.push(l - 1);
    int i = l, minVal = firstStrip.first, maxVal = firstStrip.second;
    while(i < n){
        if(arr[i] < minVal){
            if(maxVal - arr[i] > s){
                pair<int, int> firstStrip = rmq(0, l);
            }
            else{
                minVal = arr[i];
                i++;
            }
        }
        if(arr[i] > maxVal){
            if(arr[i] - minVal > s){

            }
            else{
                maxVal = arr[i];
                i++;
            }
        }
    }
}