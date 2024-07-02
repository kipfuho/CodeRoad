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

vector<int> odd, even;
int arr[100001], arr1[100001];

void sol(){
	odd.clear(), even.clear();
	int n, temp; cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> temp;
		arr[i] = temp;
		if(i&1) odd.pb(temp);
		else even.pb(temp);
	}

	int start = 1, end = n;
	sort(odd.begin(), odd.end());
	sort(even.begin(), even.end());
	reverse(even.begin(), even.end());

	for(int num : odd) arr1[num] = end--;
	for(int num : even) arr1[num] = start++;

	for(int i = 0; i < n; i++) cout << arr1[arr[i]] << " ";
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