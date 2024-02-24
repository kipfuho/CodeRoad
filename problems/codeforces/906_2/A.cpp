// https://codeforces.com/contest/1890/problem/A

#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){_
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if(n == 1) break;
        map<int, int> mp;
        int count = 0, temp;
        for(int i = 0; i < n; i++){
            cin >> temp;
            if(!mp[temp]){
                count++;
                mp[temp] = 1;
            }
            else mp[temp]++;
        }
        if(n == 2){
            cout << "Yes\n";
            continue;
        }
        if(count <= 2){
            bool valid = true;
            int prev = -1;
            for(auto& x:mp){
                if(prev == -1) prev = x.second;
                else{
                    if(n&1){
                        if(abs(x.second - prev) != 1) valid = false;
                    }
                    else{
                        if(x.second - prev != 0) valid = false;
                    }
                }
            }
            if(valid) cout << "Yes\n";
            else cout << "No\n";
        }
        else cout << "No\n";
    }
    return 0;
}