/*
Description
There are M shelves in a large warehouse 1, 2, . . ., M in which the shelf j is located at point j of the warehouse (j = 1, ..., M). 
There are N product 1, 2, . . ., N. The amount of product i in the shelf j is Q[i][j].
The warehouse staff starts from the door (point 0) of the warehouse, and want to visit some shelves 
(each shelf is visited at most once) and come back to the door to pickup products for the 
order of customers in which the total amount of product i he must pickup is q[i] (i = 1, 2, . . ., N).
The travel distance from point i to point j is d(i,j) (0 <= i,j <= M). 
Find the sequence of shelves to visit such that the total travel distance is minimal.

Input
Line 1: two positive integer N and M (1 <= N <= 50, 1 <= M <= 1000)
Line 1 + i (i = 1, ..., N): contains the ith row of Q
Line N + i + 2 (i = 0, 1, ..., M): contains the ith row of the distance matrix d 
Line N + M + 3: contains q[1], q[2], . . ., q[N]

A solution is represented by a sequence of n positive integers x1, x2, . . ., xn representing the sequence of shelves to be visited 

Output
Line 1: contains a positive integer n
Line 2: contains n positive integers x1, x2, . . ., xn

Example
Input
6 5
3 2 2 4 2 
4 3 7 3 5 
6 7 2 5 4 
2 3 3 2 1 
2 5 7 6 1 
7 2 1 6 5 
0 16 10 13 13 19 
16 0 8 3 19 5 
10 8 0 7 23 11 
13 3 7 0 16 6 
13 19 23 16 0 22 
19 5 11 6 22 0 
8 7 4 8 11 13 

Output
4
2 3 1 5 
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

int n, m, temp, temp1, next_stop[1001], check[1001], cluster[1001];
vector<array<int, 3>> arr;

bool cmp(array<int, 3> a2, array<int, 3> a1){
    return a2[2] < a1[2];
}

int main(){_
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    memset(next_stop, 0, 4*1001);
    memset(check, 0, 4*1001);
    check[0] = 1;
    cin >> n >> m; cout << m << endl;
    FOR(i, 1, n) FOR(j, 1, m) cin >> temp;
    FOR(i, 0, m){
        FOR(j, 0, m){
            cin >> temp;
            if(i == j) continue;
            arr.push_back({i, j, temp});
        }
        cluster[i] = i;
    }
    FOR(i, 1, n) cin >> temp;
    sort(arr.begin(), arr.end(), cmp);
    for(auto [u, v, w] : arr){
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
    temp = 0;
    while(next_stop[temp] != 0){
        cout << next_stop[temp] << " ";
        temp = next_stop[temp];
    }
    return 0;
}