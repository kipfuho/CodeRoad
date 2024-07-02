// https://codeforces.com/contest/1973/problem/A

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

void sol(){
	int p1, p2, p3;
	cin >> p1 >> p2 >> p3;

	if((p1 + p2 + p3) & 1) {
		cout << -1 << '\n';
		return ;
	}

	if(p1 + p2 < p3) cout << p1 + p2 << '\n';
	else cout << (p1 + p2 + p3) / 2 << '\n';

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