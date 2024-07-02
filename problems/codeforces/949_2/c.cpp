// https://codeforces.com/contest/1981/problem/C

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

int arr[200000];

void sol(){
  int n; cin >> n;
	vector<pair<int, int>> ai;
	rep(i, n) {
		cin >> arr[i];
		if(arr[i] != -1) ai.push_back({arr[i], i});
	}

	if(ai.size() == 0) {
		arr[0] = 1;
		for(int i = 1; i < n; i++) {
			if(arr[i - 1] > 1) arr[i] = arr[i - 1] / 2;
			else arr[i] = arr[i - 1] * 2;
		}

		rep(i, n) cout << arr[i] << " ";
		cout << '\n';
		return;
	}

	// begin to first ai
	for(int i = ai[0].second - 1; i >= 0; i--) {
		if(arr[i + 1] > 1) arr[i] = arr[i + 1] / 2;
		else arr[i] = arr[i + 1] * 2;
	}

	// ai in the middle
	for(int i = 1; i < ai.size(); i++) {
		int left = ai[i - 1].second, right = ai[i].second;
		
		while(left < right) {
			// 2 close element
			if(left == right - 1) {
				// dead end
				if(max(arr[left], arr[right]) / 2 != min(arr[left], arr[right])) {
					cout << "-1\n";
					return;
				}
				break;
			}

			if(arr[left] > arr[right]) {
				int start = (1 << (right - left)) * arr[right], end = start + (1 << (right - left)) - 1;
				if(arr[left] >= start && arr[left] <= end ) {
					for(int j = left + 1; j < right; j++)
						arr[j] = arr[j - 1] / 2;
				}
				else {
					// dead end
					if(arr[left] > end) {
						cout << "-1\n";
						return;
					}
					
					arr[left + 1] = arr[left] / 2;
					left++;
				}
			}
			else if(arr[left] < arr[right]) {
				int start = (1 << (right - left)) * arr[left], end = start + (1 << (right - left)) - 1;
				if(arr[right] >= start && arr[right] <= end ) {
					for(int j = right - 1; j > left; j--)
						arr[j] = arr[j + 1] / 2;
				}
				else {
					// dead end
					if(arr[right] > end) {
						cout << "-1\n";
						return;
					}
					
					arr[right - 1] = arr[right] / 2;
					right--;
				}	
			}
			else {
				if(arr[left] > 1) arr[left + 1] = arr[left] / 2;
				else arr[left + 1] = arr[left] * 2;
				left++;
			}
		}
	}
	
	// last ai to end
	for(int i = ai[ai.size() - 1].second + 1; i < n; i++) {
		if(arr[i - 1] > 1) arr[i] = arr[i - 1] / 2;
		else arr[i] = arr[i - 1] * 2;
	}

	rep(i, n) cout << arr[i] << " ";
	cout << '\n';
	return;
}

void sol1() {
	int n; cin >> n;
	rep(i, n) cin >> arr[i];

	int prev = 0;
	rep(i, n) {
		if(arr[i] != -1) {
			int l = prev, r = i;
			while(l < r) {
				if(l == r - 1) {
					if(l == 0 && arr[l] == -1) {
						arr[l] = arr[r] > 1 ? arr[r] / 2 : arr[r] * 2;
						break;
					}
					if(max(arr[l], arr[r]) / 2 != min(arr[l], arr[r])) {
						cout << "-1\n";
						return;
					}

					break;
				}
				else {
					if(arr[l] >= arr[r]) {
						arr[l + 1] = arr[l] > 1 ? arr[l] / 2 : arr[l] * 2;
						l++;
					}
					else {
						arr[r - 1] = arr[r] > 1 ? arr[r] / 2 : arr[r] * 2;
						r--;
					}
				}
			}
			prev = i;
		}
	}

	if(prev == 0 && arr[0] == -1) {
		arr[0] = 1;
	}
	rep(i, prev + 1, n) {
		if(arr[i - 1] > 1) arr[i] = arr[i - 1] / 2;
		else arr[i] = arr[i - 1] * 2;
	}

	rep(i, n) cout << arr[i] << " ";
	cout << '\n';

	return;
}

int main(){_
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t; cin >> t;
    while(t--){
        sol1();
    }
    return 0;
}