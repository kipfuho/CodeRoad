// https://codeforces.com/contest/1877/problem/A

#include<bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int res = 0;
        for(int i = 0; i < n - 1; i++){
            int temp; cin >> temp;
            res -= temp;
        }
        cout << res << endl;
    }
}