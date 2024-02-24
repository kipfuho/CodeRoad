/*
Description
Given a tree T=(V,E) in which V={1,. . ., n} is the set of nodes. Each edge (u,v) of T has length w(u,v). Denote f(v) the sum of length of paths from all other nodes to v. Write a program to compute max{f(1), .  . ., f(n)}.

Input
Line 1 contains a positive integer n (2 <= n <= 10^5)
Line i+1 (i=1, . . ., n): contains u, v and w in which w is the weight of the edge (u,v)
Output
Write the value max{f(1), . . , f(n}.

Example
Input
4
1 2 1
1 3 3
3 4 2
Output
13
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

int n, u, v, w, child[100001], length[100001], sumpath[100001];
vector<vector<pii>> g;

void dfs(int u, int pre){
    child[u] = 1, length[u] = 0, sumpath[u] = 0;
    for(pii v:g[u]){
        if(v.first == pre) continue;
        dfs(v.first, u);
        length[u] += child[v.first]*v.second;
        length[u] += length[v.first];
        child[u] += child[v.first];
    }
    return;
}

void dfs2(int u, int pre){
    for(pii v:g[u]){
        if(v.first == pre) continue;
        // calculate f - length of all vertices from u and child of u to u
        // int f = sumpath[u] - length[v.first] - v.second*child[v.first];
        // f + v.second*(n - child[v.first]) = length of all vectices, which is u and child of u on the other side, to v
        // sumpath[v] = length[v.first] + f + v.second*(n - child[v.first]);
        sumpath[v.first] = sumpath[u] + v.second*(n - 2*child[v.first]); 
        dfs2(v.first, u);
    }
    return;
}

int main(){_
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> n;
    g.resize(n+1, vector<pii>());
    FOR(i, 1, n-1){
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dfs(1, 0);
    sumpath[1] = length[1];
    dfs2(1, 0);
    int maxlength = 0;
    FOR(i, 1, n) maxlength = max(maxlength, sumpath[i]);
    cout << maxlength;
    return 0;
}