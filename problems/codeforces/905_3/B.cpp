// https://codeforces.com/contest/1883/problem/B

#include<bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k; n -= k;
        string s; cin >> s;
        map<char, int> mp;
        for(auto& x:s) mp[x]++;
        bool valid = true;
        if(n&1){
            int odd = 0;
            for(auto& x:mp){
                if(x.second&1){
                    if(odd > k){
                        valid = false;
                        break;
                    }
                    odd++;
                }
            }
        }
        else{
            int odd = 1;
            for(auto& x:mp){
                if(x.second&1){
                    if(odd > k){
                        valid = false;
                        break;
                    }
                    odd++;
                }
            }
        }
        if(valid) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}