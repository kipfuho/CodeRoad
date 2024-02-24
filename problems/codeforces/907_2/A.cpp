// https://codeforces.com/contest/1891/problem/A

#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ull unsigned long long
#define ll long long

using namespace std;

int arr[21];

int main(){_
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i = 1; i <= n; i++) cin >> arr[i];
        bool valid = true;
        for(int i = 1; (1<<i) <= n; i++){
            for(int j = (1<<i) + 1; j <= min(n, 1<<(i+1)) - 1; j++){
                if(arr[j] > arr[j+1]){
                    valid = false;
                    break;
                }
            }
        }
        if(valid) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}