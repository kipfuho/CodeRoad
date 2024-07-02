// https://codeforces.com/contest/1974/problem/F

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
#define eb emplace_back
#define endl '\n'
#define YES cout << "YES\n";
#define NO cout << "NO\n";
#define Yes cout << "Yes\n";
#define No cout << "No\n";
#define bit(x) (x & (-x))

using namespace std;

vector<int> cx, cy;
int a, b, n, m;

void sol(){
  cx.clear(), cy.clear();

	cin >> a >> b >> n >> m;
	rep(n) {
		int x, y;
		cin >> x >> y;
		cx.pb(x);
		cy.pb(y);
	}
	
	sort(cx.begin(), cx.end());
	sort(cy.begin(), cy.end());

	ll alice = 0, bob = 0, turn = 0;
	ll l = 0, r = cy.size() - 1, u = 0, d = cx.size() - 1; // binary search scope
	rep(m) {
		char op; int k;
		cin >> op >> k;
		ll t1, t2, temp;
		switch (op)
		{
		case 'U':
			t1 = u, t2 = d, temp = INT_MAX;
			while(t1 <= t2) {
				ll mid = (t1 + t2) / 2;
				if(cx[mid] > k) {
					temp = min(temp, mid);
					t2 = mid - 1;
				}
				else t1 = mid + 1;
			}
			if(turn&1) bob += temp - u;
			else alice += temp - u;
			break;
		case 'D':
			t1 = u, t2 = d, temp = INT_MIN;
			while(t1 <= t2) {
				ll mid = (t1 + t2) / 2;
				if(cx[mid] < k) {
					temp = max(temp, mid);
					t1 = mid + 1;
				}
				else t2 = mid - 1;
			}
			cout << temp;
			if(turn&1) bob += d - temp;
			else alice += d - temp;
			break;
		case 'L':
			t1 = l, t2 = r, temp = INT_MAX;
			while(t1 <= t2) {
				ll mid = (t1 + t2) / 2;
				if(cy[mid] > k) {
					temp = min(temp, mid);
					t2 = mid - 1;
				}
				else t1 = mid + 1;
			}
			if(turn&1) bob += temp - l;
			else alice += temp - l;
			break;
		case 'R':
			t1 = l, t2 = r, temp = INT_MIN;
			while(t1 <= t2) {
				ll mid = (t1 + t2) / 2;
				if(cy[mid] < k) {
					temp = max(temp, mid);
					t1 = mid + 1;
				}
				else t2 = mid - 1;
			}
			if(turn&1) bob += r - temp;
			else alice += r - temp;
			break;
			break;
		
		default:
			break;
		}
	}

	cout << alice << " " << bob << endl;
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