/* https://codeforces.com/group/Ir5CI6f3FD/contest/276073/problem/B
B. NETWORKS
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
The network administrator of a company have to analyze the current state of 
their communication network all over the world. The communication network 
consists of servers and cable links between these servers, each link has a 
cost. A k-route is a sequence of k+1 different servers in which two 
consecutive servers are connected by a cable link. A cycle is a k-route 
(for any k>1) such that the beginning and the terminating servers are 
connected by a cable link. The communication network contains no cycle. 
The cost of a k-route is the sum of cost of links between two consecutive 
servers of the k-route. One of the indicators of the analysis is the k-route 
having minimal cost of the network for a given value of k.

Given the communication network G and an integral value k, help the network 
administrator to find the k-route having minimal cost of G.

Input
The input consists of following lines

Line 1: contains two integer n and k (1≤n≤10000, 1≤k≤2000) in which n is the 
number of servers of the communication network G (servers are numbered 1,2,...,n)
Line 2: contains an integer m (1≤m≤10000) which is the number of cable links 
between servers of G
Line i+2: contains three integers u, v, and w: u and v are two end points of 
the ith link of G (∀i=1,…,m), w is the cost of this link.
Output
The output contains the cost of the k-route found.

Example
input
6 2
5
1 2 4
1 4 1
1 5 3
1 6 2
2 3 1
output
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

int n, k, m, parent[10001], dp[10001][2001], minatk[2001];
int u, v, w;
vector<int, vector<pii>> g(10001, vector<pii>());

int main(){_
    //freopen("in.in", "r", stdin);
    //freopen("out.out", "w", stdout);
    cin >> n >> k >> m;
    FOR(i, 1, m){
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    int mincost = 1<<30;
    return 0;
}