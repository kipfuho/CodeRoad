// https://codeforces.com/contest/1899/problem/C

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

int n, curmax;
int arr[200001], dp[200001];

void sol(){
    cin >> n;
    FOR(i, 1, n) cin >> arr[i];
    dp[1] = arr[1];
    FOR(i, 2, n){
        if((arr[i]&1) != (arr[i - 1]&1)){
            dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        }
        else dp[i] = arr[i];
    }
    curmax = dp[1];
    FOR(i, 2, n) curmax = max(curmax, dp[i]);
    cout << curmax << endl;
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