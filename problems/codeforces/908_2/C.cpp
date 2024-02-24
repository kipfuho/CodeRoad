// https://codeforces.com/contest/1894/problem/C

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

int arr[200001], save[200001];

void sol(){
    int n, k, temp; cin >> n >> k;
    bool valid = true;
    FOR(i, 1, n) cin >> arr[i];

    int i = n;
    while(k--){
        if(save[i]) break;
        else if(arr[i] > n){
            valid = false;
            break;
        }
        save[i] = 1;
        i = (i - arr[i] + n)%n;
    }
    
    if(valid) Yes
    else No

    FOR(i, 1, n) save[i] = 0;
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