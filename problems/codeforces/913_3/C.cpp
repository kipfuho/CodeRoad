// https://codeforces.com/contest/1907/problem/C

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
    int arr[26];
    memset(arr, 0, 4*26);
    int n; cin >> n;
    string s; cin >> s;
    for(auto c:s) arr[c-'a']++;
    sort(arr, arr + 26);
    FOR(i, 1, 24){
        arr[i] += arr[i - 1];
    }
    if(arr[25] > arr[24]) cout << arr[25] - arr[24] << endl;
    else{
        if(n&1) cout << "1\n";
        else cout << "0\n";
    }
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