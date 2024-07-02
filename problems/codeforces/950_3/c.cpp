// https://codeforces.com/contest/1980/problem/C

#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rep1(a) for (int i = 0; i < (a); i++)
#define rep2(i, a) for (int i = 0; i < (a); i++)
#define rep3(i, a, b) for (int i = a; i < (b); i++)
#define rep4(i, a, b, c) for (int i = a; i < (b); i += (c))
#define overload4(a, b, c, d, e, ...) e
#define rep(args...) overload4(args, rep4, rep3, rep2, rep1)(args)
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

int arr[200000], brr[200000], drr[200000];

void sol(){
  int n; cin >> n;
	rep(i, n) cin >> arr[i];
	rep(i, n) cin >> brr[i];
	int m; cin >> m;
	rep(i, m) cin >> drr[i];
	
	map<int, int> mp;
	map<int, bool> check;
	int diff = 0;
	rep(i, n) {
		if(arr[i] != brr[i]) {
			if(mp[brr[i]]) mp[brr[i]]++;
			else {
				mp[brr[i]] = 1;
				diff++;
			}
		}
		check[brr[i]] = true;
	}

	int err = 0;
	rep(i, m) {
		if(check[drr[i]]) {
			if(mp[drr[i]] > 0) {
				mp[drr[i]]--;
				if(mp[drr[i]] == 0) diff--;
			}
			err = 0;
		}
		else {
			err++;
		}
	}

	if(diff || err) cout << "no\n";
	else cout << "yes\n";
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