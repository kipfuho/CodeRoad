// https://codeforces.com/contest/1881/problem/C

#include<bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n][n];
        long long res = 0;
        for(int i = 0; i < n; i++){
            string s; cin >> s;
            for(int j = 0; j < n; j++){
                arr[i][j] = s[j] - 'a';
            }
        }
        int len = n/2;
        if(n&1) len++;
        for(int i = 0; i < len; i++){
            for(int j = 0; j < len; j++){
                int a = arr[i][j], 
                    b = arr[j][n - i - 1], 
                    c = arr[n - i - 1][n - j - 1], 
                    d = arr[n - j - 1][i];
                
                int min4 = 4*max(max(a, b), max(c, d));
                res += (min4 - a - b - c - d);
            }
        }
        cout << res << endl;
    }
    return 0;
}