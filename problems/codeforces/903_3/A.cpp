// https://codeforces.com/contest/1881/problem/A

#include<bits/stdc++.h>
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, m;
        string x, s;
        cin >> n >> m;
        cin >> x >> s;
        int count;
        bool valid = false;
        for(int i = n - 1; i >=0; i--){
            if(x[i] == s[m - 1]){
                int k = i - 1;
                count = 0;
                valid = true;
                for(int j = m - 2; j >= 0; j--){
                    if(k < 0){
                        k = n - 1;
                        count++;
                    }
                    if(s[j] != x[k]){
                        valid = false;
                        break;
                    }
                    k--;
                }
            }

            if(valid) break;
        }
        
        if(valid){
            int res;
            if(count == 0) res = 0;
            else res = log2(count) + 1;
            cout << res << endl;
        }
        else cout << "-1\n";
    }
    // do not return 1 in codeforces;
}