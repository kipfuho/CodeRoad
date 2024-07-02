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

void sol(){
	int n, m, temp; cin >> n >> m;
	vector<vector<int>> mat1(n, vector<int>(m)), mat2(n, vector<int>(m));
	vector<int> pos1i(n*m), pos1j(n*m), pos2i(n*m), pos2j(n*m);

	rep(i, n) rep(j, m) {
		cin >> mat1[i][j];
		pos1i[mat1[i][j] - 1] = i;
		pos1j[mat1[i][j] - 1] = j;
	}

	rep(i, n) rep(j, m) {
		cin >> mat2[i][j];
		pos2i[mat2[i][j] - 1] = i;
		pos2j[mat2[i][j] - 1] = j;
	}

	vector<set<int>> pi(n, set<int>()), pj(m, set<int>());
	rep(i, n*m) {
		pi[pos1i[i]].insert(pos2i[i]);
		pj[pos1j[i]].insert(pos2j[i]);
	}

	for(auto s : pi) {
		if(s.size() > 1) {
			cout << "no\n";
			return;
		}
	}

	for(auto s : pj) {
		if(s.size() > 1) {
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