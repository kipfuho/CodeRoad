// https://codeforces.com/contest/1883/problem/C

#include<bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        int min_operation = k;
        if(k == 4){
            int even = 0;
            for(int i = 0; i < n; i++){
                int temp; cin >> temp;
                if(temp%2 == 0) even++;
                min_operation = min(min_operation, (k - temp%k)%k);
            }
            if(even > 1) min_operation = 0;
            else min_operation = min(2 - even, min_operation);
        }
        else{
            for(int i = 0; i < n; i++){
                int temp; cin >> temp;
                min_operation = min(min_operation, (k - temp%k)%k);
            }
        }
        cout << min_operation << endl;
    }
    return 0;
}