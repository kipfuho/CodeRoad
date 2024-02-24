/* https://codeforces.com/group/Ir5CI6f3FD/contest/281925/problem/B
B. Planting Trees
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Farmer Jon has recently bought n
 tree seedlings that he wants to plant in his yard. It takes 1
 day for Jon to plant a seedling: {Jon isn't particularly hardworking.}, and for each tree Jon knows exactly in how many days after planting it grows to full maturity. Jon would also like to throw a party for his farmer friends, but in order to impress them he would like to organize the party only after all the trees have grown. More precisely, the party can be organized at earliest on the next day after the last tree has grown up.

Help Jon to find out when is the earliest day when the party can take place. Jon can choose the order of planting the trees as he likes, so he wants to plant the trees in such a way that the party will be as soon as possible.

Input
The input consists of two lines. The first line contains a single integer N
 (1≤N≤100000
) denoting the number of seedlings. Then a line with N
 integers ti
 follows (1≤ti≤1000000
), where ti
 denotes the number of days it takes for the i
th tree to grow.

Output
You program should output exactly one line containing one integer, denoting the earliest day when the party can be organized. The days are numbered 1,2,3,…
 beginning from the current moment.

Example
inputCopy
1
1
outputCopy
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

int timeg[100001];
int n;

int main(){_
    //freopen("in.in", "r", stdin);
    //freopen("out.out", "w", stdout);
    cin >> n;
    FOR(i, 1, n) cin >> timeg[i];
    sort(timeg + 1, timeg + n + 1);
    int earliest = 0, j = 1;
    FOD(i, n, 1){
        earliest = max(earliest, timeg[i] - n + j++);
    }
    earliest += (n+1);
    cout << earliest;
    return 0;
}