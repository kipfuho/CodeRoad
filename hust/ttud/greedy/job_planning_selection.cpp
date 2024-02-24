/*
Description
Given n jobs J = {1,. . .,n}. Each job i has a deadline d(i) and associated profit p(i) if the job is finished before the deadline. Every job takes the single unit of time, so the minimum possible deadline for any job is 1. It is also noted that no more than one job can be executed at a time.
Select and schedule a subset of jobs of J such that the total profits is maximal.
Input
Line 1: contains a positive integer n (1 <= n <= 10^5)
Line i+1 (i=1,. . . ,n) contains d(i) and p(i) (1 <= d(i), p(i) <= 10^5)
Output
Write to total profits obtained from the subset of jobs found.

Example
Input
6
3 10
2 40
6 70
3 50
5 80
1 60
Output
300
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

ll maxprofit = 0, n, dtemp, ptemp;
bool check[100001];
pll DATA[100001];
vector<int> arr;

bool cmp(pll p2, pll p1){
    if(p2.first > p1.first) return true;
    else if(p2.first == p1.first) return p2.second < p1.second;
    else return false;
}

int main(){_
    //freopen("in.in", "r", stdin);
    //freopen("out.out", "w", stdout);
    cin >> n;
    FOR(i, 1, n){
        cin >> dtemp >> ptemp;
        DATA[i] = {ptemp, dtemp};
        check[i] = true;
    }
    sort(DATA + 1, DATA + n + 1, cmp);
    FOR(i, 1, n){
        pll pairtemp = DATA[i];
        FOD(j, pairtemp.second, 1){
            if(check[j]){
                maxprofit += pairtemp.first;
                check[j] = false;
                break;
            }
        }
    }
    cout << maxprofit;
    return 0;
}