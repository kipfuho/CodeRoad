//

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

int main(){
	int n; string s;
	cout << "Input index of array to query: "; cin >> n;
    freopen("out1.txt", "r", stdin);
    FOR(i, 1, n){
		getline(cin, s);
	} 
	cout << "Array " << n << ":\n" << s;
    return 0;
}