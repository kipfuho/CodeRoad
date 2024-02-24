/* https://codeforces.com/group/Ir5CI6f3FD/contest/281925/problem/C
C. ATM
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Vinh works for an ATM machine manufacturing company. The basic functionality of an ATM machine is cash withdrawal. When a user requests a cash withdrawal of W
 VND (Vietnamese Dong), the ATM has to dispense N
 money notes such that they sum up to W
. For the next generation of ATM machines, Vinh is working on an algorithm to minimize the number of N
 of money notes for each cash withdrawal transaction.

Your task is to help Vinh to do his job given that the money notes come in the values of 1000,2000,3000,5000,1000⋅101,2000⋅101,3000⋅101,5000⋅101,…,1000⋅10c,2000⋅10c,3000⋅10c,5000⋅10c
 where c
 is a positive integer and Vinh has unlimited supply of money notes for each value.

Input
The input file consists of several datasets. The first line of the input file contains the number of datasets which is a positive integer and is not greater than 1000. The following lines describe the datasets.

The first line consists of one positive integer W (W≤1018
);

The second line consists of one positive integer c
 (c≤15
).

Output
For each dataset, write in one line two space-separated integers N
 and S
 where S
 is the number of ways to dispense the fewest number N
 of money notes. In case there is no way to serve the cash withdrawal request, write out 0 in one line instead.

Example
inputCopy
2
1000
1
7000
1
outputCopy
1 1
2 1
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

ll w, c, cnote[45], n, s;

int main(){_
    //freopen("in.in", "r", stdin);
    //freopen("out.out", "w", stdout);
    cnote[1] = 1, cnote[2] = 2, cnote[3] = 3, cnote[4] = 5;
    FOR(i, 1, 15){
        FOR(j, 1, 4){
            cnote[4*i + j] = cnote[j]*pow(10, i);
        }
    }
    int t; cin >> t;
    while(t--){
        cin >> w >> c;
    }
    return 0;
}