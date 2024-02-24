// https://codeforces.com/contest/1898/problem/C

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

ll n, m, k;
char arr1[16][16], arr2[16][16];

void prep(){
    FOR(i, 1, 15) FOR(j, 1, 15){
        if(j&1){
            arr1[i][j] = 'R'; 
            arr2[i][j] = 'B';
        }
        else{
            arr1[i][j] = 'B'; 
            arr2[i][j] = 'R';
        }
    }
    arr2[1][2] = 'B';
}

void sol(){
    cin >> n >> m >> k;
    if((n + m - 2) > k) NO
    else{
        int time4 = k/4, remain4 = k%4, pathlen = n + m - 2;
        k = (pathlen/4)*4 + remain4 - pathlen;
        if(k < 0) k += 4;

        if(k&1) NO
        else{
            YES
            FOR(i, 1, n){
                FOR(j, 1, m-1) cout << arr1[i][j] << " "; 
                cout << endl;
            }
            FOR(i, 1, m){
                FOR(j, 1, n-1) cout << arr2[i][j] << " "; 
                cout << endl;
            }
        }
    }
}

int main(){_
    //freopen("in.in", "r", stdin);
    //freopen("out.out", "w", stdout);
    int t; cin >> t;
    prep();
    while(t--){
        sol();
    }
    return 0;
}