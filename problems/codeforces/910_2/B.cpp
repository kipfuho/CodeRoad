// https://codeforces.com/contest/1898/problem/B

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

ll n, last_element, min_op, arr[200001], temp;

void sol(){
    cin >> n;
    FOR(i, 1, n) cin >> arr[i];
    min_op = 0, last_element = arr[n];
    FOD(i, n-1, 1){
        if(arr[i] > last_element){
            temp = (arr[i] - 1)/last_element;
            min_op += temp;
            last_element = arr[i] / (temp + 1);
        }
        else last_element = arr[i];
    }
    cout << min_op << endl;
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