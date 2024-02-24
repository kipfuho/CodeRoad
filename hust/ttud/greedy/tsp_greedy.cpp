/*
Description
There are n cities 1, 2, ..., n. The travel distance from city i to city j is c(i,j), for i,j = 1, 2, ..., n.  A person departs from city 1, visits each city 2, 3, ..., n exactly once and comes back to city 1. Find the itinerary for that person so that the total travel distance is minimal.
Input
Line 1: a positive integer n (1 <= n <= 1000)
Line i+1 (i = 1, . . ., n): contains the ith row of the distance matrix x (elements are separated by a SPACE character)
Output
Line 1: write n 
Line 2: write the sequence of points x
1
, x
2
, . . ., x
n
 (a permutation of 1, 2, . . ., n) of the itinerary found.
Example
Input
4
0 1 1 9
1 0 9 3
1 9 0 2
9 3 2 0
Output
4
1 3 2 4
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

//int w_mat[1001][1001]
int n, temp, temp1, next_stop[1001], check[1001], cluster[1001];
vector<array<int, 3>> edges;

bool cmp(array<int, 3> a2, array<int, 3> a1){
    return a2[2] < a1[2];
}

int main(){_
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    memset(next_stop, 0, 4*1001);
    memset(check, 0, 4*1001);
    check[1] = 1;

    cin >> n; cout << n << endl;
    FOR(i, 1, n){
        FOR(j, 1, n){
            cin >> temp;
            //w_mat[i][j] = temp;
            if(i == j) continue;
            edges.push_back({i, j, temp});
        }
        cluster[i] = i;
    }

    sort(edges.begin(), edges.end(), cmp);
    for(auto [u, v, w] : edges){
        temp = u, temp1 = v;
        while(cluster[temp] != temp){
            cluster[temp] = cluster[cluster[temp]];
            temp = cluster[temp];
        }
        while(cluster[temp1] != temp1){
            cluster[temp1] = cluster[cluster[temp1]];
            temp1 = cluster[temp1];
        }
        if(!next_stop[u] && (temp != temp1) && !check[v]){
            next_stop[u] = v;
            check[v] = 1;
            cluster[v] = temp;
        }
    }

    //for(auto [u, v, w] : edges) cout << u << " " << v << " " << w << endl;
    //FOR(i, 1, n) cout << next_stop[i] << " ";
    temp = 1;
    while(temp != 0){
        cout << temp << " ";
        temp = next_stop[temp];
    }
    return 0;
}