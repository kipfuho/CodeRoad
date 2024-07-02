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

map<char, int> hexVal;
map<int, int> delta;
vector<string> first;

inline int calculatDelta(string x, string y) {
	int r = (16*hexVal[x[1]] + hexVal[x[2]] + 256 - 16*hexVal[y[1]] - hexVal[y[2]])%256,
			g = (16*hexVal[x[3]] + hexVal[x[4]] + 256 - 16*hexVal[y[3]] - hexVal[y[4]])%256,
			b = (16*hexVal[x[5]] + hexVal[x[6]] + 256 - 16*hexVal[y[5]] - hexVal[y[6]])%256;

	//r = min(r, 256 - r);
	//g = min(g, 256 - g);
	//b = min(b, 256 - b);

	return 256*256*r + 256*g + b;
}

void sol(){
	int n; cin >> n;
	string temp;
	rep(n) {
		cin >> temp;
		first.pb(temp);
	}

	int maxFre = 1;
	rep(i, n) {
		cin >> temp;
		int d = calculatDelta(temp, first[i]);
		if(delta[d]) delta[d]++;
		else delta[d] = 1;
		maxFre = max(maxFre, delta[d]);
	}

	printf("%.2f%%", static_cast<double>(maxFre) / n * 100.0);
	return;
}

int main(){_
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
		hexVal['0'] = 0;
		hexVal['1'] = 1;
		hexVal['2'] = 2;
		hexVal['3'] = 3;
		hexVal['4'] = 4;
		hexVal['5'] = 5;
		hexVal['6'] = 6;
		hexVal['7'] = 7;
		hexVal['8'] = 8;
		hexVal['9'] = 9;
		hexVal['A'] = 10;
		hexVal['B'] = 11;
		hexVal['C'] = 12;
		hexVal['D'] = 13;
		hexVal['E'] = 14;
		hexVal['F'] = 15;
    sol();
    return 0;
}