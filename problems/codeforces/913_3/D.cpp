// https://codeforces.com/contest/1907/problem/D

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

int n, LEFT, MID, RIGHT, t1, t2, kmin;
pii arr[200001], cur;
bool check;

void sol(){
    cin >> n;
    FOR(i, 1, n){
        cin >> t1 >> t2;
        arr[i] = {t1, t2};
    }
    LEFT = 0, RIGHT = 1e9;
    while(LEFT <= RIGHT){
        MID = (LEFT + RIGHT)/2;
        check = true, cur = {0, 0};
        FOR(i, 1, n){
            if(cur.first > arr[i].second){
                if(cur.first - arr[i].second > MID){
                    check = false;
                    break;
                }
                cur = {max(arr[i].first, cur.first - MID), arr[i].second};
            }
            else if(cur.second < arr[i].first){
                if(arr[i].first - cur.second > MID){
                    check = false;
                    break;
                }
                cur = {arr[i].first, min(arr[i].second, cur.second + MID)};
            }
            else{
                cur = {max(arr[i].first, cur.first - MID), min(arr[i].second, cur.second + MID)};
            }
        }
        if(check){
            kmin = MID;
            RIGHT = MID - 1;
        }
        else{
            LEFT = MID + 1;
        }
    }
    cout << kmin << endl;
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