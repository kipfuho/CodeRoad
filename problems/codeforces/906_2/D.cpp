// https://codeforces.com/contest/1890/problem/D

#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

bool cmp(pair<int, long long> p2, pair<int, long long> p1){
    if(p2.second > p1.second) return true;
    else return false;
}

int main(){_
    int t; cin >> t;
    while(t--){
        long long n, c; cin >> n >> c;
        vector<pair<int, long long>> arr;
        vector<long long> value(n+1);
        long long temp;
        for(long long i = 1; i <= n; i++){
            cin >> temp;
            arr.push_back({i, temp - i*c}); // may throw signed int overflow if c and n big
            value[i] = temp;
        }
        
        //cout << "still fine\n";
        sort(arr.begin(), arr.end(), cmp);
        bool valid = true;
        long long sum = value[1];
        
        for(auto& x:arr){
            if(x.first == 1) continue;
            if(sum + value[x.first] >= x.first*c) sum += value[x.first];
            else{
                valid = false;
                break;
            }
        }
        
        if(valid) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}