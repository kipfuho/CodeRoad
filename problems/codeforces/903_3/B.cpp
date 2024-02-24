// https://codeforces.com/contest/1881/problem/B

#include<bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == b && a == c) cout << "YES\n";
        else{
            if(a > b) swap(a, b);
            if(b > c) swap(b, c);
            if(a > b) swap(a, b);
            int sum = a + b + c;
            if(b%a == 0 && c%a == 0){
                if(sum == 6*a || sum == 5*a || sum == 4*a) cout << "YES\n";
                else cout << "NO\n";
            }
            else cout << "NO\n";
        }
    }
    return 0;
}