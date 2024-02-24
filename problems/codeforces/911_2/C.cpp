// https://codeforces.com/contest/1900/problem/C

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

int minop;
string letter;
pii node[300001];

void dfs(int i, int curreplace){
    if(node[i].first == 0 && node[i].second == 0){
        minop = min(minop, curreplace);
        return;
    }
    if(node[i].first != 0) dfs(node[i].first, curreplace + (letter[i] != 'L'));
    if(node[i].second != 0) dfs(node[i].second, curreplace + (letter[i] != 'R'));
    return;
}

void sol(){
    int n, t1, t2; cin >> n >> letter;
    letter = " " + letter;
    FOR(i, 1, n){
        cin >> t1 >> t2;
        node[i] = {t1, t2};
    }
    minop = 1<<30;
    dfs(1, 0);
    cout << minop << endl;
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