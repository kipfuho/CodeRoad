// https://codeforces.com/contest/1973/problem/B

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

ll arr[100000];

void sol(){
	int n; cin >> n;
	for(int i = 0; i < n; i++) cin >> arr[i];

	ll maxNum = arr[0], curNum = arr[0];
	int index = 0, result = n - 1;

	for(int i = 1; i < n; i++) {
		curNum |= arr[i];
		if(curNum == arr[i]) {
			index = i;
		}
		if(curNum > maxNum) {
			maxNum = curNum;
			index = i;
		}
	} 
	
	cout << result + 1 << '\n';
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