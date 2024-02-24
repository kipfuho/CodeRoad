/* https://codeforces.com/group/Ir5CI6f3FD/contest/257967/problem/A
A. COUNT SPANNING TREES
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Given a undirected connected graph G=(V,E) in which V={1,…,N} is the set of nodes and E is the set of M edges. Count the number of spanning trees of G.

Input
Line 1: contains positive integers N and M (1≤N≤20,1≤M≤25)
Line i+1 (i=1,…,M): contains u and v which are endpoints of the ith edge of G
Output
Write the number of spanning trees of G

Example
inputCopy
4 5
1 2
1 3
1 4
2 3
3 4
outputCopy
8
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

int n, m, cluster[21], total_spanning_tree = 0;
pii edges[26];

int getcluster(int u){
    while(u != cluster[u]){
        u = cluster[u];
    }
    return u;
}

void TRY(int i, int count){
    if(count == n - 1){
        total_spanning_tree++;
        return;
    }
    if(i > m) return;
    int u = edges[i].first, v = edges[i].second, cluster1 = getcluster(u), cluster2 = getcluster(v);
    if(cluster1 == cluster2) TRY(i+1, count);
    else{
        cluster[cluster1] = cluster2;
        TRY(i+1, count+1);
        cluster[cluster1] = cluster1;
        TRY(i+1, count);
    }
    return;
}

int main(){_
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> n >> m;
    FOR(i, 1, n) cluster[i] = i;
    FOR(i, 1, m){
        int u, v; cin >> u >> v;
        edges[i] = {u, v};
    }
    TRY(1, 0);
    cout << total_spanning_tree;
    return 0;
}