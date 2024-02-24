#include<bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<pair<int, int>> arr;
        for(int i = 0; i < n; i++){
            int l, r; cin >> l >> r;
            arr.push_back({l, r});
        }
        auto cmp = [](pair<int, int> pair2, pair<int, int> pair1){
            if(pair2.second > pair1.second) return true;
            else{
                if(pair2.first < pair1.first) return true;
                else return false;
            }
        }
        sort(arr.begin(), arr.end(), cmp);
        int max
    }
    return 0;
}