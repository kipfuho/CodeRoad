// https://codeforces.com/contest/1899/problem/F

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

int n, l, r, op_num;
bool valid;
int arr[200001];

void sol(){
    cin >> n;
    FOR(i, 1, n) cin >> arr[i];
    l = 1, r = n, op_num = 0, valid = true;
    while(l < r){
        if(arr[l] <= arr[r]){
            if(arr[r - 1] > arr[r]) valid = false;
            r--;
        }
        else{
            l++;
            op_num++;
        }
    }

    if(valid) cout << op_num << endl;
    else cout << "-1\n";
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