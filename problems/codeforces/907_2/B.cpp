// https://codeforces.com/contest/1891/problem/B

#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ull unsigned long long
#define ll long long

using namespace std;

ll arr[100001], save[31];

int main(){_
    int t; cin >> t;
    while(t--){
        int n, q, temp, last_temp = 31; cin >> n >> q;
        bool have_one = false;
        for(int i = 1; i <= n; i++){
            cin >> arr[i];
        }
        for(int i = 1; i <= 30; i++) save[i] = 0;
        for(int i = 1; i <= q; i++){
            cin >> temp;
            if(temp > last_temp) continue;
            else{
                for(int j = temp; j <= 30; j++) save[j] += 1<<(temp - 1);
                last_temp = temp - 1;
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 30; j > 0; j--){
                if(arr[i] % (1<<j) == 0){
                    arr[i] += (save[j]);
                    break;
                }
            }
        }
        for(int i = 1; i <= n; i++) cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}