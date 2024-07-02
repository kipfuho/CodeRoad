// https://codeforces.com/contest/1974/problem/B

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

int mark[26];

void sol(){
	for(int i = 0; i < 26; i++) mark[i] = 0;
	int n;
  string s;
	cin >> n >> s;
	for(char c : s) mark[c - 'a'] = 1;
	int l = 0, r = 25;
	while(l < r) {
		if(!mark[l]) {
			l++;
			continue;
		}
		if(!mark[r]) {
			r--;
			continue;
		}
		mark[l] = r;
		mark[r] = l;
		l++, r--;
	}
	if(l == r) mark[l] = l;
	for(char c : s) cout << static_cast<char>('a' + mark[c - 'a']);
	cout << '\n';
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