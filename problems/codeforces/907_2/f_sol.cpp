#include <bits/stdc++.h>
#define endl '\n'
#define rep(i, j, k) for (int i = int(j); i <= int(k); i++)
#define per(i, j, k) for (int i = int(j); i >= int(k); i--)
#define debug(x) cerr << "(" << __LINE__ << ")" << #x << " = " << x << endl;
#define debug0(tmp, Size) rep(i, 0, Size - 1) cout << tmp[i] << " \n"[i == Size - 1]
#define debug1(tmp, Size) rep(i, 1, Size) cout << tmp[i] << " \n"[i == Size]
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define Yes cout << "Yes\n"
#define No cout << "No\n"
typedef long long ll;
// #define mid (l + r) << 1;
#define lc (i << 1)
#define rc (i << 1 & 1)
#define pb push_back
#define pii pair<int, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define pli pair<ll, int>
#define sd second
#define ft first
using namespace std;

const int N = 5e5 + 10, mod = 1e9 + 7;

typedef long long ll;

std::vector<int> h[N];
std::vector<std::array<int, 3>> ops;
int l[N], r[N], idx;
ll tr[N];
int n, m;

int lowbit(int x) { return x & -x; }
void add(int x, ll k)
{
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += k;
}
ll sum(int x)
{
    ll res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}

void dfs(int u)
{
    l[u] = ++idx;
    for (auto v : h[u])
    {
        dfs(v);
    }
    r[u] = idx;
}

void solve()
{
    std::cin >> m;
    n = 1;

    for (int i = 1; i <= m; i++)
    {
        int op, v, x;
        std::cin >> op;
        if (op == 1)
        {
            ++n;
            std::cin >> v;
            h[v].push_back(n);
            ops.push_back({op, v, n});
        }
        else
        {
            std::cin >> v >> x;
            ops.push_back({op, v, x});
        }
    }

    dfs(1);
    for (auto [op, v, x] : ops)
    {
        if (op == 1)
        {
            ll res = sum(l[x]);
            add(l[x], -res), add(r[x] + 1, res);
        }
        else
        {
            add(l[v], x), add(r[v] + 1, -x);
        }
    }

    for (int i = 1; i <= n; i++)
        std::cout << sum(l[i]) << " \n"[i == n];
    for (int i = 1; i <= n; i++)
    {
        h[i].clear();
        tr[i] = 0;
        l[i] = r[i] = 0;
    }
    idx = 0;
    ops.clear();
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t = 1;
    std::cin >> t;
    for (int i = 1; i <= t; i++)
        solve();
    return 0;
}