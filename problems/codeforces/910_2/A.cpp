// https://codeforces.com/contest/1898/problem/A

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

int n, k, count_b;
string s;

void sol(){
    cin >> n >> k >> s;
    count_b = 0;
    FOD(i, n-1, 0) if(s[i] == 'B') count_b++;
    if(count_b == k) cout << "0\n";
    else if(count_b > k){
        FOR(i, 0, n-1){
            if(s[i] == 'B') count_b--;
            if(count_b == k){
                cout << "1\n" << i + 1 << " A\n";
                break;
            }
        }
    }
    else{
        FOR(i, 0, n-1){
            if(s[i] == 'A') count_b++;
            if(count_b == k){
                cout << "1\n" << i + 1 << " B\n";
                break;
            }
        }
    }
}

int main(){_
    //freopen("in.in", "r", stdin);
    //freopen("out.out", "w", stdout);
    int t; cin >> t;
    while(t--){
        sol();
    }
    return 0;
}