// https://codeforces.com/contest/1980/problem/D

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

int arr[200000], brr[200000];

int gcd(int x, int y) {
	if(y == 0) return x;
	return gcd(y, x%y);
}

void sol(){
	// input
  int n; cin >> n;
	rep(i, n) cin >> arr[i];
	rep(i, n - 1) brr[i] = gcd(arr[i], arr[i + 1]);
	if(n == 3) {
		cout << "yes\n";
		return;
	}

	// remove if a element in arr is removed
	bool remove = false;
	rep(i, n - 2) {
		if(brr[i] > brr[i + 1]) {
			// cannot remove 2 elements
			if(remove) {
				cout << "No\n";
				return;
			}

			if(i == n - 3) break;

			remove = true;
			// greed for best remove
			int temp;
			if(i < n - 3) {
				temp = gcd(arr[i + 1], arr[i + 3]);
				if(temp >= brr[i] && temp <= (i < n - 4 ? brr[i + 3] : INT_MAX)) {
					brr[i + 1] = brr[i + 2] = temp;
					i += 2;
					continue;
				}
			}
			
			temp = gcd(arr[i], arr[i + 2]);
			if(temp <= (i < n - 3 ? brr[i + 2] : INT_MAX) && temp >= (i > 0 ? brr[i - 1] : -1)) {
				brr[i] = brr[i + 1] = temp;
				i++;
				continue;
			}
			
			if(i == 0) continue;
			else {
				temp = gcd(arr[i - 1], arr[i + 1]);
				if(temp <= brr[i + 1] && temp >= (i > 1 ? brr[i - 2] : -1)) {
					brr[i - 1] = brr[i] = temp;
					continue;
				}
			}

			cout << "no\n";
			return;
		}
	}

	cout << "yes\n";
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