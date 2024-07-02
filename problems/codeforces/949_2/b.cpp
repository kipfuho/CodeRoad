// https://codeforces.com/contest/1981/problem/B

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

void sol(){
	ll n, m; cin >> n >> m;

	ll range = n + m - max(0LL, n - m),
			leftMost = max(0LL, n - m),
			clone = leftMost,
			maxbin = 1,
			sum = 0;

	while(leftMost > 0) {
		if(leftMost%2 == 0 && maxbin >= range) {
			break;
		}
		if(leftMost&1) sum += maxbin;
		clone |= maxbin;
		leftMost >>= 1;
		maxbin <<= 1;
	}

	while(maxbin < range) {
		clone |= maxbin;
		maxbin <<= 1;
	}

	if(sum + range >= maxbin) clone |= maxbin;
	cout << clone << '\n';
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