// https://codeforces.com/contest/1974/problem/E

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

ll m, x, hap[50], cost[50], dp[100001];

void sol(){
	ll sum = 0;
	cin >> m >> x;
	for(ll i = 0; i < m; i++) {
		cin >> cost[i] >> hap[i];
		sum += hap[i];
	}
	for(ll i = 0; i <= sum; i++) dp[i] = -1;

	dp[0] = 0;
	if(cost[0] == 0) dp[hap[0]] = 0;
  for(ll i = 1; i < m; i++) {
		ll c = cost[i], h = hap[i];
		for(ll j = sum; j >= h; j--) {
			if(dp[j - h] >= 0) {
				dp[j - h] += x;
				dp[j] = max(dp[j], dp[j - h] - c);
			}
		}
	}

	for(int i = sum; i >= 0; i--) {
		if(dp[i] >= 0) {
			cout << i << '\n';
			break;
		}
	}
	return;
}

int main(){_
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t; cin >> t;
    while(t--){
        sol();
    }
    return 0;
}