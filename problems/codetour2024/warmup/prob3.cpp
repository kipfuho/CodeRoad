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

pii directions[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void sol(){
	int n; cin >> n;
	int mat[100][100];
	map<array<int, 3>, bool> vis;

	rep(i, 100) rep(j, 100) mat[i][j] = 0;

	rep(i, n) {
		int x, y; cin >> x >> y;
		if(x >= 100 || y >= 100) return;
		mat[x][y] = -1;
	}

	int m; cin >> m;
	queue<pair<pii, pii>> q;
	int idx = 0;
	rep(i, m) {
		int u, v; cin >> u >> v;
		if(u >= 100 || v >= 100) return;
		mat[u][v] = -1;
		q.push({{u, v}, {1, idx++}});
	}

	while(!q.empty()) {
		pair<pii, pii> item = q.front();
		q.pop();
		for(auto dir : directions) {
			int x = dir.first + item.first.first, y = dir.second + item.first.second;
			if(x >= 0 && x < 100 && y >= 0 && y < 100 && mat[x][y] != -1 && !vis[{x, y, item.second.second}]) {
				vis[{x, y, item.second.second}] = true;
				mat[x][y] += item.second.first;
				q.push({{x, y}, {item.second.first + 1, item.second.second}});
			}
		}
	}

	int minn = INT_MAX;
	rep(i, 100) rep(j, 100)
		if(mat[i][j] != -1) minn = min(minn, mat[i][j]);
	cout << minn;
	return;
}

int main(){_
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    sol();
    return 0;
}