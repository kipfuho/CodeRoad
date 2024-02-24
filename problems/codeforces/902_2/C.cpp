// https://codeforces.com/contest/1877/problem/C

#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    int t; cin >> t;
    while(t--){
        int n, m, k; cin >> n >> m >> k;
        int res = n;
        if(m > n){
            res += (m - n) / n;
        }
        
        if(k > 3) cout << 0 << endl;
        else if(k == 1){
            cout << 1 << endl;
        }
        else if(k == 2){
            if(n > m){
                cout << m << endl;
            }
            else cout << res << endl;
        }
        else{
            if(n >= m){
                cout << 0 << endl;
            }
            else cout << m - res << endl;
        }
    }
}