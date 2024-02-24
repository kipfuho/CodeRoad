// https://codeforces.com/contest/1890/problem/B

#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){_
    int T; cin >> T;
    while(T--){
        int n, m; cin >> n >> m;
        string s, t; cin >> s >> t;
        bool is_s_good = true, is_t_good = true, valid;
        int t_type;
        for(int i = 0; i < n - 1; i++){
            if(s[i] == s[i + 1]){
                is_s_good = false;
                break;
            }
        }
        for(int i = 0; i < m - 1; i++){
            if(t[i] == t[i + 1]){
                is_t_good = false;
                break;
            }
        }
        if(!is_t_good){
            if(!is_s_good) cout << "No\n";
            else cout << "Yes\n";
        }
        else{
            if(is_s_good) cout << "Yes\n";
            else{
                if(m == 1) t_type = t[0];
                else{
                    if(t[0] != t[m-1]){
                        cout << "No\n";
                        continue;
                    }
                    else t_type = t[0];
                }
                
                valid = true;
                for(int i = 0; i < n - 1; i++){
                    if(s[i] == s[i+1]){
                        if(s[i] == t_type){
                            valid = false;
                            break;
                        }
                    }
                }
                if(valid) cout << "Yes\n";
                else cout << "No\n";
            }
        }
    }
    return 0;
}
