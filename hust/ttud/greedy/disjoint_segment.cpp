#include<bits/stdc++.h>

using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vector<pair<int, int>> arr;
    int count = 0, last = -1;
    for(int i = 0; i < n; i++){
        int left, right;
        cin >> left >> right;
        arr.push_back({left, right});
    }
    auto cmp = [](pair<int, int> pair2, pair<int, int> pair1){
        if(pair2.second < pair1.second) return true;
        else return false;
    };
    sort(arr.begin(), arr.end(), cmp);
    for(auto& x:arr){
        int left = x.first, right = x.second;
        if(left > last){
            count++;
            last = right;
        }
        else{
            if(last > right) last = right;
        }
    }
    cout << count;
}