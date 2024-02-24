/* https://codeforces.com/group/Ir5CI6f3FD/contest/276073/problem/A
Description
The Kingdom ALPHA has n warehouses of golds located on a straight line and 
are numbered 1, 2,..., n. The warehouse i has amount of a_i
(ai is non-negative integer) and is located at coordinate i (i=1,...,n). 
The King of ALPHA opens a competition for hunters who are responsible to find 
a subset of gold warehouses having largest total amount of golds with respect 
to the condition that the distance between two selected warehouses must be 
greater than or equal to L1 and less than or equal to L2.
Input
Line 1 contains n, L1, and L2 (1≤n≤1000000,1≤L1≤L2≤n)
Line 2 contains n integers a1,a2,…,an
Output
Contains only one single integer denoting the total amount of golds of 
selected warehouses.
Example
Input
6 2 3
3 5 9 6 7 4

Output
19
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

ll n, l1, l2, maxshift, arr[1000001], dp[1000001];
bool check;
queue<pll> q;
pll curpair;

int main(){_
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> n >> l1 >> l2;
    maxshift = l2 - l1;
    FOR(i, 1, n) cin >> arr[i];

    dp[1] = arr[1];
    curpair = {arr[1], 1};
    FOR(i, 2, l1){
        if(curpair.first > arr[i] && maxshift >= (i - curpair.second)){
            dp[i] = curpair.first;
            q.push({arr[i], i});
        }
        else{
            check = true;
            while(!q.empty()){
                curpair = q.front();
                q.pop();
                if(curpair.first > arr[i]){
                    check = false;
                    break;
                }
            }
            if(curpair.first <= arr[i] || check){
                curpair = {arr[i], i};
            }
            dp[i] = curpair.first;
        }
    }
    FOR(i, l1 + 1, n){
        if(curpair.first > (dp[i - l1] + arr[i]) && maxshift >= (i - curpair.second)){
            dp[i] = curpair.first;
            q.push({dp[i], i});
        }
        else{
            while(!q.empty()){
                curpair = q.front();
                q.pop();
                if(curpair.first > (dp[i - l1] + arr[i])) break;
            }
            if(curpair.first <= (dp[i - l1] + arr[i])){
                curpair = {(dp[i - l1] + arr[i]), i};
            }
            dp[i] = curpair.first;
        }
    }
    ll maximum = arr[1];
    FOR(i, 1, n) maximum = max(maximum, dp[i]);
    cout << maximum;
    return 0;
}