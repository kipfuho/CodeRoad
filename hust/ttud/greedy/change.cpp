/* https://codeforces.com/group/Ir5CI6f3FD/contest/281925/problem/A
A. CHANGE
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Minh go shopping at the SS shop. The shop has currency denominations: 1$, 5$, 10$, 50$, 100$, 500$. Minh takes some items at the shop and pay an amount of 1000$. Your task to devise a method to pay back amount to customer using fewest number of money notes.

Input
The input consists of only one single integer N
 (1≤N≤999
) denoting the total value of the taken items.

Output
The output consists of only one single integer denoting the number of money notes.

Examples
inputCopy
1
outputCopy
15
inputCopy
3
outputCopy
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

int val[6] = {500, 100, 50, 10, 5, 1};

int main(){_
    //freopen("in.in", "r", stdin);
    //freopen("out.out", "w", stdout);
    int n, timet = 0; cin >> n;
    n = 1000 - n;
    FOR(i, 0, 5){
        timet += n/val[i];
        n %= val[i];
    }
    cout << timet;
    return 0;
}