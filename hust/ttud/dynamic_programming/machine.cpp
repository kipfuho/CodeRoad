/*
E. 05. MACHINE
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output

An engineer needs to schedule a machine to run on some given periods 1,…,n to produce a chemical product C. 
Each period i is represented by a starting time point si and terminating time point ti (si<ti). 
Due to a technical constraint, the machine must run on exactly two periods that are not overlap 
(two periods i and j are not overlap if ti<sj or tj<si). If the machine is runned on the period i, then the 
amount of C it will produce is equal to the duration of the period i (which is equal to ti−si). 
Help the engineer to select two not-overlap periods to run the machine such that the amount of C produced is maximal.

Input
Line 1: contains the positive integer n (2≤n≤2⋅10^6)
Line i+1: contains two positive integer si and ti (1≤si<ti≤2⋅10^6)
Output
The output consists of only one single integer which is the amount of product C the machine will produce in the 
two selected periods. In case there is no solution (there does not exist two periods that are not overlap), 
the output contains the value -1.

Example
input
5
8 12
6 11
3 9
2 5
1 4

output
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

int n, s, t, maxstart[2000001], maxend[2000001], bestpair = -1;

int main(){_
    //freopen("in.in", "r", stdin);
    //freopen("out.out", "w", stdout);
    cin >> n;
    FOR(i, 1, 2000000) maxstart[i] = maxend[i] = 0;
    FOR(i, 1, n){
        cin >> s >> t;
        maxstart[s] = max(maxstart[s], t-s);
        maxend[t] = max(maxend[s], t-s);
    }
    FOD(i, 1999999, 1) maxstart[i] = max(maxstart[i + 1], maxstart[i]);
    FOR(i, 2, 2000000) maxend[i] = max(maxend[i - 1], maxend[i]);

    FOR(i, 2, 2000000) if(maxstart[i] != 0 && maxend[i - 1] != 0) bestpair = max(bestpair, maxstart[i] + maxend[i - 1]);
    cout << bestpair;
    return 0;
}