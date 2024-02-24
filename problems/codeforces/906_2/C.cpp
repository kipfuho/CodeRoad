// https://codeforces.com/contest/1890/problem/C

#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){_
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        int count_zero = 0, count_one = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '0') count_zero++;
            else count_one++;
        }
        if(count_zero != count_one) cout << "-1\n";
        else{
            vector<int> save_position;
            int p = 0, i = 0;
            while(i < n/2){
                if(s[i] == s[n - i - 1]){
                    if(s[i] == '0'){
                        save_position.push_back(n + p - i);
                        p++;
                        for(int j = i; j < n - i - 1; j++){
                            s[j] = s[j + 1];
                        }
                        s[n - i - 1] = '0';
                    }
                    else{
                        save_position.push_back(i + p);
                        p++;
                        for(int j = n - i - 1; j > i; j--){
                            s[j] = s[j - 1];
                        }
                        s[i] = '1';
                    }
                }
                else i++;
            }
            cout << p << endl;
            for(auto& x:save_position) cout << x << " ";
            cout << endl;
        }
    }
    return 0;
}