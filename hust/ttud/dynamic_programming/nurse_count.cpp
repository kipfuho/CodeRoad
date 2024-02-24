/* https://codeforces.com/group/Ir5CI6f3FD/contest/276073/problem/F
Description
The director of a hospital want to schedule a working plan for a nurse in a 
given period of N consecutive days 1,..., N. Due to the policy of the hospital, 
each nurse cannot work all the days 1,..., N. Instead, there must be days off 
in which the nurse need to take a rest. A working plan is a sequence of disjoint 
working periods. A working period of a nurse is defined to be a sequence of 
consecutive days on which the nurse must work and the length of the working 
period is the number of consecutive days of that working period. The hospital 
imposes two constraints:

-Each nurse can take a rest only one day between two consecutive working periods. 
it means that if the nurse takes a rest today, then she has to work tomorrow (1)

-The length of each working period must be greater or equal to K1 and less than or 
equal to K2 (2)

The director of the hospital want to know how many possible working plans 
satisfying above constraint?

Input
The input consists of one line which contains 3 positive integers N, K1, K2 
(2 <= N <=  1000, K1 < K2 <= 400)

Output
The output consists of only one single integer M modulo 10^9+7 where M is the 
total working plans satisfying the above constraints.

Example
Input
6 2 3

Output
4
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
#define MOD 1000000009

using namespace std;

ll n, k1, k2, dp[1002];

int main(){_
    //freopen("in.in", "r", stdin);
    //freopen("out.out", "w", stdout);
    cin >> n >> k1 >> k2;
    FOR(i, 1, n) dp[i] = 0;
    FOR(i, k1, k2){
        dp[i + 1]++;
        dp[i + 2]++;
    }
    FOR(i, k1, n){
        FOR(j, k1, k2){
            if(i - j < 1) break;
            if(i != n) dp[i + 1] = (dp[i + 1] + dp[i - j])%MOD;
            else dp[i] = (dp[i] + dp[i - j])%MOD;
        }
    }
    cout << dp[n];
    return 0;
}