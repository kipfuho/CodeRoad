// https://codeforces.com/contest/1974/problem/C

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
#define endl '\n';

using namespace std;

int n, arr[200001];
ll total = 0;
map<array<int, 3>, int> mp;
map<pair<int, int>, int> duo0, duo1, duo2;

void sol(){
	mp.clear(), duo0.clear(), duo1.clear(), duo2.clear();
	total = 0;

	cin >> n;
	for(int i = 0; i < n; i++) cin >> arr[i];
	
	for(int i = 0; i < n - 2; i++) {
		mp[{arr[i], arr[i + 1], arr[i + 2]}]++;
	}

	for(auto item : mp) {
		array<int, 3> trip = item.first;
		int a = trip[0], b = trip[1], c = trip[2], times = item.second;

		if(duo2[{a, b}]) {
			total += times*duo2[{a, b}];
		}
		if(duo1[{a, c}]) {
			total += times*duo1[{a, c}];
		}
		if(duo0[{b, c}]) {
			total += times*duo0[{b, c}];
		}
		duo2[{a, b}] += times;
		duo1[{a, c}] += times;
		duo0[{b, c}] += times;
	}
	cout << total << endl;
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