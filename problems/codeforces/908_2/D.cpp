// https://codeforces.com/contest/1894/problem/D

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

int arr1[200001], arr2[200001];

void sol(){
    int n, m; cin >> n >> m;
    FOR(i, 1, n) cin >> arr1[i];
    FOR(i, 1, m) cin >> arr2[i];

    int p1 = 1, p2 = 1;
    sort(arr2 + 1, arr2 + m + 1, greater<int>());
    while(p1 <= n && p2 <= m){
        if(arr1[p1] > arr2[p2]) cout << arr1[p1++] << " ";
        else cout << arr2[p2++] << " ";
    }
    while(p1 <= n) cout << arr1[p1++] << " ";
    while(p2 <= m) cout << arr2[p2++] << " ";
    cout << endl;
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