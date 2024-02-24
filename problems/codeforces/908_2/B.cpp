// https://codeforces.com/contest/1894/problem/B

#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define FOD(i, r, l) for(int i = r; i >= l; i--)
#define ull unsigned long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define YES cout << "YES\n";
#define NO cout << "NO\n";
#define Yes cout << "Yes\n";
#define No cout << "No\n";
#define bit(x) (x & (-x))

using namespace std;

int arr[101], res[101];
map<int, int> mp;

void sol(){
    int n, count = 0;
    cin >> n;
    FOR(i, 1, n){
        cin >> arr[i];
        if(count < 2){
            if(mp[arr[i]] == 0){
                mp[arr[i]] = i;
                res[i] = 1;
            }
            else if(mp[arr[i]] != -1){
                count++;
                if(count == 1){
                    res[i] = 2;
                }
                else if(count == 2){
                    res[i] = 3;
                }
                mp[arr[i]] = -1;
            }
            else res[i] = 1;
        }
        else{
            res[i] = 1;
        }
    }

    if(count > 1){
        FOR(i, 1, n) cout << res[i] << " ";
        cout << endl;
    }
    else{
        cout << "-1\n";
    }

    mp.clear();
}

int main(){_
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    int t; cin >> t;
    while(t--){
        sol();
    }
    return 0;
}