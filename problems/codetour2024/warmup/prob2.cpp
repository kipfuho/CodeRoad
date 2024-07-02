//

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

int cal(double n, double m, double x) {
	double d1 = x * sqrt(3), d2 = 3.0 * x / 2.0;
	double a = n / d1, b = (m - x) / d2 + 1;
	if(a < floor(a + 1.0) && a > floor(a)) a = floor(a + 1.0);
	if(b < floor(b + 1.0) && b > floor(b)) b = floor(b + 1.0);
	
	int c = static_cast<int>(a);
	int d = static_cast<int>(b);
	
	if((c*d1 - d1 / 2.0) >= n)
		return c*d;
	else
		return c*d + d / 2;
}

void sol() {
	double n, m, x; cin >> n >> m >> x;
	int v1 = cal(n, m, x), v2 = cal(m, n, x);
	cout << min(v1, v2) << '\n';
	return;
}

int main(){_
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
		int t; cin >> t;
    while(t--) sol();
    return 0;
}