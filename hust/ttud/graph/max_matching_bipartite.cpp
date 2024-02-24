/*
Description
There are  n tasks 1,. . .,n and m staffs 1, . . , m. T(i) is the set of staffs that can perform the task i (i=1, . . ., n). Compute an assignment of staffs to tasks such that each task is assigned to at most one staff and each staff cannot be assigned to more than one task and the number of tasks assigned is maximal.
Input
Line 1: contains 2 positive integer n và m (1 <=  n,m <= 10000)
Line i+1 (i=1, . . .,n) contains a positive integer k and k integer of T(i)
Output
Write the maximum number of tasks that are assigned to staffs.
Example
Input
3 4
2 1 4
2 1 3
1 2

Output
3
*/

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

int n, m, staff[10001];
vector<vector<int>> g;
bool visited[10001];

// trying to find an augment path
bool dfs(int u){
    if(visited[u]) return false;
    visited[u] = true;
    for(int v:g[u]){
        if(!staff[v] || dfs(staff[v])){
            staff[v] = u;
            return true;
        }
    }
    return false;
}

int main(){_
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> n >> m;
    g.resize(n+1, vector<int>());
    memset(staff, 0, 4*(m+1));
    FOR(i, 1, n){
        int len; cin >> len;
        FOR(j, 1, len){
            int u; cin >> u;
            g[i].push_back(u);
        }
    }
    FOR(i, 1, n){
        memset(visited, false, n+1);
        dfs(i);
        //FOR(j, 1, m)cout << staff[j] << " "; cout << endl;
    }
    int max_match = 0;
    FOR(i, 1, m){
        if(staff[i]) max_match++;
    }
    cout << max_match;
    return 0;
}