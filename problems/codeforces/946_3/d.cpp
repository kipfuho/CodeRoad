// https://codeforces.com/contest/1974/problem/D

#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define FOD(i, r, l) for(int i = r; i >= l; i--)
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
  int instr[4] = {0, 0, 0, 0}, n;
	string s;
	cin >> n >> s;
	for(auto c : s) {
		switch (c)
		{
		case 'N':
			instr[0]++;
			break;

		case 'S':
			instr[1]++;
			break;

		case 'E':
			instr[2]++;
			break;

		case 'W':
			instr[3]++;
			break;
		
		default:
			break;
		}
	}
	int earlyCheck = instr[0] + instr[1] + instr[2] + instr[3];
	if(earlyCheck < 4) {
		if(earlyCheck & 1) {
			NO
			return;
		}
		if(instr[0] < 2 && instr[1] < 2 && instr[2] < 2 && instr[3] < 2) {
			NO
			return;
		}
		cout << "RH\n";
		return;
	}
	if(earlyCheck == 4){
		if(instr[0] == 1 && instr[1] == 1 && instr[2] == 1) {
			for(char c : s) {
				if(c == 'N' || c == 'S') cout << 'R';
				else cout << 'H';
			}
			cout << '\n';
			return;
		} else if ((instr[0] == instr[1] && instr[0] == 2) || (instr[2] == instr[3] && instr[2] == 2)) {
			int a1 = 0, a2 = 0;
			for(char c : s) {
				if(c == 'N' || c == 'W') {
					if(!a1) {
						cout << 'R';
						a1++;
					} else cout << 'H';
				}
				else {
					if(!a2) {
						cout << 'R';
						a2++;
					} else cout << 'H';
				}
			}
			cout << "\n";
			return;
		}
	}

	for(auto& i : instr) i %= 2;
	if((instr[0] == instr[1]) && (instr[2] == instr[3])) {
		for(auto c : s)
			switch (c)
			{
			case 'N':
				if(instr[0] & 1) cout << 'H';
				else cout << 'R';
				instr[0]++;
				break;

			case 'S':
				if(instr[1] & 1) cout << 'H';
				else cout << 'R';
				instr[1]++;
				break;

			case 'E':
				if(instr[2] & 1) cout << 'H';
				else cout << 'R';
				instr[2]++;
				break;

			case 'W':
				if(instr[3] & 1) cout << 'H';
				else cout << 'R';
				instr[3]++;
				break;
			
			default:
				break;
			}
		cout << '\n';
	} else NO

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