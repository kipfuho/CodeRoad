/*
Description
The chair of a conference must assign scientific papers to reviewers in a balance way. There are N papers 1, 2, …, N and M reviewers 1, 2, …, M. Each paper i has a list L(i) of reviewers who are willing to review that paper. A review plan is an assignment reviewers to papers. The load of a reviewer is the number of papers he/she have to review. Given a constant b, compute the assignment such that:
Each paper is reviewed by exactly b reviewers 
The maximum load of all reviewers is minimal
In the solution, each paper i is represented by a list r(i, 1), r(i, 2), . . ., r(i, b) of b reviewers asssigned to this paper
Input
Line 1 contains N, M and b
Line i+1 (i = 1,…,N) contains a positive integer k followed by k positive integers representing the list L(i)
Output
Line 1: contains N
Line i + 1 (i = 1, . . ., N): contains b and b integers r(i, 1), r(i, 2), . . ., r(i, b) which are the list of reivewers assigned to paper i
Example
Input
5 3 2
3 1 2 3 
2 1 2 
3 1 2 3 
3 1 2 3 
2 1 3 
Output
5
2 1 2
2 1 2
2 3 1
2 3 2
2 3 1
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

int n, m, b, temp;
int arr[1001][1001], rweight[1001], rchoose[1001][1001];
pii len[1001], temparr[1001], tpair;

int main(){_
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    memset(rweight, 0, 4004);
    cin >> n >> m >> b;
    FOR(i, 1, n){
        cin >> temp;
        len[i] = {temp, i};
        FOR(j, 1, temp) cin >> arr[i][j];
    }
    sort(len + 1, len + 1 + n);
    FOR(i, 1, n){
        tpair = len[i];
        FOR(j, 1, tpair.first){
            temparr[j] = {rweight[arr[tpair.second][j]], arr[tpair.second][j]};
        }
        sort(temparr + 1, temparr + 1 + tpair.first);
        FOR(j, 1, b){
            rchoose[tpair.second][j] = temparr[j].second;
            rweight[temparr[j].second]++;
        }
    }
    cout << n << endl;
    FOR(i, 1, n){
        cout << b << " ";
        FOR(j, 1, b) cout << rchoose[i][j] << " ";
        cout << endl;
    }
    return 0;
}