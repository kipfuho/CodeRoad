#include <bits/stdc++.h>

#define fi first
#define se second
#define For(i, a, b) for (int i = a; i <= b; ++i)
#define Ford(i, a, b) for (int i = a; i >= b; --i)

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef array<int, 3> arr;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

const int N = 2 * 1e5 + 5;

int val[] = { 1, 3, 5, 10, 30, 50, 100, 300, 500, 1000, 3000, 5000, 10000, 30000, 50000 };
int cntval = 15;

int calc(int t) {
    int ans = 0;
    Ford(i, cntval - 1, 0)  // if (t >= val[i])
        ans += t / val[i],
        t %= val[i];
    return ans;
}

void solve() {
    int x, t;
    cin >> x >> t;
    int ans = calc(t);
    int st = min(t % x + 50010 * x, t);
    cout<<"st: "<<st<<endl;
    for (; st >= 0; st -= x) {
        if ((t - st) / x >= ans)
            break;
        ans = min(ans, (t - st) / x + calc(st));
    }
    for (int i = 0; i <= 50000 && t >= 0; t -= x, i++) {
        if (i >= ans)
            break;
        ans = min(ans, calc(t) + i);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

    // cerr << 1.0 * clock() / CLOCKS_PER_SEC;

    return 0;
}