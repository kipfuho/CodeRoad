/* https://codeforces.com/group/Ir5CI6f3FD/contest/276073/problem/U
U. 03. KNAPSAC
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Một nhà thám hiểm cần đem theo một cái túi có trọng lượng không quá b
. Có n
 đồ vật có thể đem theo. Đồ vật thứ j
 có trọng lượng aj
 và giá trị sử dụng cj
. Hỏi nhà thám hiểm cần đem theo những đồ vật nào để cho tổng giá trị sử dụng là lớn nhất mà tổng trọng lượng đồ vật mang theo cái túi không vượt quá b
?

Input
Dòng đầu tiên chứa hai số nguyên dương n,b
 (n≤30,b≤106
).

Dòng thứ j
 trong số n
 dòng tiếp theo mỗi dòng ghi ra hai số nguyên dương aj,cj≤106
.

Output
Ghi ra duy nhất một số là tổng giá trị lớn nhất tìm được của các đồ vật cho vào túi.

Example
inputCopy
2 6
4 2
3 2
outputCopy
2
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

pii items[31];
int dp[1000001], check[1000001], n, b, temp1, temp2, bestval = 0;

bool cmp(pii p2, pii p1){
    return p2.second > p1.second;
}

int main(){_
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> n >> b;
    FOR(i, 1, n){
        cin >> temp1 >> temp2;
        items[i] = {temp1, temp2};
    }
    sort(items + 1, items + n + 1, cmp);
    FOR(i, 1, n){
        temp1 = items[i].first, temp2 = items[i].second;
        if(temp2 > dp[temp1]){
            dp[temp1] = temp2;
            check[temp1] = i;
        }
        FOR(j, temp1 + 1, b){
            if(check[j - temp1] != i && dp[j - temp1] > 0){
                if(dp[j - temp1] + temp2 > dp[j]){
                    dp[j] = dp[j - temp1] + temp2;
                    check[j] = i;
                }
            }
        }
    }
    
    FOR(i, 1, b) bestval = max(bestval, dp[i]);
    cout << bestval;
    return 0;
}