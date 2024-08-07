// https://codeforces.com/contest/1899/problem/B

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

ll n, curmin, curmax, cursum, curbest;
int arr[150001];

void sol(){
    cin >> n;
    FOR(i, 1, n) cin >> arr[i];
    curbest = 0;
    FOR(k, 1, n/2){
        if(n%k == 0){
            curmin = 1LL<<60LL, curmax = 0;
            FOR(i, 1, n/k){
                cursum = 0;
                FOR(j, (i - 1)*k + 1, i*k){
                    cursum += arr[j];
                }
                curmin = min(cursum, curmin);
                curmax = max(cursum, curmax);
            }
            curbest = max(curbest, curmax - curmin);
        }
    }
    cout << curbest << endl;
}

int main(){_
    //freopen("in.in", "r", stdin);
    //freopen("out.out", "w", stdout);
    int t; cin >> t;
    while(t--){
        sol();
    }
    return 0;
}