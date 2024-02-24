// https://codeforces.com/contest/1877/problem/B

#include<bits/stdc++.h>

using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        int n, p; cin >> n >> p;
        vector<pair<int, int>> arr(n);
        for(int i = 0; i < n; i++){
            int temp; cin >> temp;
            arr[i].first = temp;
        }
        for(int i = 0; i < n; i++){
            int temp; cin >> temp;
            arr[i].second = temp;
        }  

        auto cmp = [](pair<int, int> a, pair<int, int> b){
            if(a.second < b.second) return true;
            else if(a.second == b.second && a.first < b.first) return true;
            else return false;
        };

        sort(arr.begin(), arr.end(), cmp);
        long long res = p, left = n - 1, i = 0;
        for(; i < n; i++){
            if(arr[i].second > p) break;
            if(arr[i].first >= left){
                res += left*arr[i].second;
                left = 0;
                break;
            }
            res += arr[i].first*arr[i].second;
            left -= arr[i].first;
        }
        res += p*left;
        cout << res << endl;
    }
}