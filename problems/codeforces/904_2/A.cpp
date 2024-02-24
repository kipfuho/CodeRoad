// https://codeforces.com/contest/1884/problem/A

#include<bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int x, k; cin >> x >> k;
        while(1){
            int temp = x, sum = 0;
            while(temp > 0){
                sum += temp%10;
                temp /= 10;
            }
            if(sum%k == 0) break;
            x++;
        }
        cout << x << endl;
    }
    return 0;
}