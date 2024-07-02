#include<bits/stdc++.h>
using namespace std;

vector<int> zfunction(string s) {
	int n = s.size(), l = 0, r = 0;
	vector<int> z(n, 0);
	for(int i = 1; i < n; i++) {
		if(i < r) z[i] = min(z[i - l], r - i);
		while(i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
		if(i + z[i] > r) l = i, r = i + z[i];
	}
	return z;
}

int main() {
	string s; cin >> s;
	vector<int> z = zfunction(s);
	for(int i : z) cout << i << " ";
}