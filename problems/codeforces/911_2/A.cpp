// https://codeforces.com/contest/1900/problem/A

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
    int n, temp = 0, res = 0; cin >> n;
    string s; cin >> s;
    for(auto x:s){
        if(x == '.') temp++;
        else{
            res += temp;
            temp = 0;
        }
        if(temp == 3){
            cout << "2\n";
            return;
        }
    }
    cout << res + temp << endl;
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