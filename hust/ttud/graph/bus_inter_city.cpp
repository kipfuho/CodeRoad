/*
Description
Có n thành phố 1, 2, ..., n. Giữa 2 thành phố i và j có thể có 1 con đường (2 chiều) kết nối giữa chúng. 
Mỗi thành phố i có tuyến buýt i với C[i] là giá vé mỗi khi lên xe và D[i] là số thành phố tối đa mà buýt i có thể đi đến trên 1 hành trình đi qua các con đường kết nối.
Hãy tìm cách đi từ thành phố 1 đến thành phố n với số tiền phải trả là ít nhất
Input
Dòng 1: chứa 2 số nguyên dương n và m trong đó n là số thành phố và m là số con đường kết nối các thành phố (1 <= n <= 5000, 1 <= m <= 10000)
Dòng i+1 (i = 1,2,...,n): chứa 2 số nguyên dương C[i] và D[i] (1 <= C[i] <= 10000, 1 <= D[i] <= 100)
Dòng n+1+i (i = 1, 2, ..., m): chứa 2 số nguyên dương i và j trong đó giữa thành phố i và j có con đường kết nối
Output
Số tiền tối thiểu phải bỏ ra để đi buýt từ thành phố 1 đến thành phố n

Example
Input
6 6
10 2
30 1
50 1
20 3
30 1
20 1
1 2
1 3
1 5
2 4
2 5
4 6
Output
30

Giải thích: 
-Lên buýt 1 từ thành phố 1 đến thành phố 4 mất 10 đồng
-Lên buýt 4 từ thành phố 4 đến thành phố 6 mất 20 đồng
Tổng cộng mất 10 + 20 = 30 đồng
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

class compare{
    public:
    bool operator() (pair<int, int> p2, pair<int, int> p1){
        return p2.second > p1.second;
    }
};

int n, m, dmatrix[5001][5001], deep[5001];
bool visited[5001];
vector<vector<int>> g;
queue<int> q;
pii dandc[5001];

void bfs(int s){
    FOR(i, 1, n){
        visited[i] = false;
        deep[i] = 0;
    }
    int cost = dandc[s].first, timebus = dandc[s].second;
    q.push(s);
    visited[s] = true;
    while(!q.empty()){
        int qf = q.front();
        q.pop();
        if(dmatrix[s][qf] <= cost) continue;
        dmatrix[s][qf] = cost;

        if(deep[qf] < timebus){
            for(int v:g[qf]){
                if(!visited[v]){
                    visited[v] = true;
                    q.push(v);
                    deep[v] = deep[qf] + 1;
                }
            }
        }
    }
    return;
}

int dijsktra(int s, int t){
    int D[n + 1];
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> heap;
    FOR(i, 1, n){
        D[i] = 100000000;
        visited[i] = false;
    }
    D[s] = 0;
    heap.push({s, 0});
    while(!heap.empty()){
        pii top = heap.top();
        heap.pop();

        int u = top.first, cost = top.second;
        if(visited[u]) continue;
        visited[u] = true;

        FOR(v, 1, n){
            if(D[v] > cost + dmatrix[u][v]){
                D[v] = cost + dmatrix[u][v];
                heap.push({v, D[v]});
            }
        }
    }
    return D[t];
}

int main(){_
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> n >> m;
    g.resize(n+1, vector<int>());
    FOR(i, 1, n){
        FOR(j, 1, n) dmatrix[i][j] = 100000000;
    }
    FOR(i, 1, n){
        int c, d; cin >> c >> d;
        dandc[i] = {c, d};
    }
    FOR(i, 1, m){
        int u, v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    //time_t start = clock();
    FOR(i, 1, n - 1) bfs(i);
    //cout << "bfstime " << clock() - start << endl;
    cout << dijsktra(1, n);
    return 0;
}