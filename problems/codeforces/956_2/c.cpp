//

#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rep1(a) for (int i = 0; i < (a); i++)
#define rep2(i, a) for (int i = 0; i < (a); i++)
#define rep3(i, a, b) for (int i = a; i < (b); i++)
#define rep4(i, a, b, c) for (int i = a; i < (b); i += (c))
#define overload4(a, b, c, d, e, ...) e
#define rep(args...) overload4(args, rep4, rep3, rep2, rep1)(args)
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

// safe hash function for unordered_map and gp_hash_table
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

// fenwick tree
struct ftree{
    int n;
    vector<int> arr;

    ftree(int size) {
        n = size + 1;
        arr.resize(n + 1, 0);
    }

    void reset() {
        fill(arr.begin(), arr.end(), 0);
    }

    void update(int x, int val) {
        x++; // move to 1-indexed
        while(x <= n){
            arr[x] += val;
            x += bit(x);
        }
    }

    // prefix sum up to r
    ll prefix_sum(int r) {
        ll res = 0;
        while(r > 0) {
            res += (ll)arr[r];
            r -= bit(r);
        }
        return res;
    }

    // sum from l to r - 1
    ll get_sum(int l, int r) {
        if(l > 0) {
            return prefix_sum(r) - prefix_sum(l);
        } else {
            return prefix_sum(r);
        }
    }
};

vector<int> arr(200000), brr(200000), crr(200000);
int n;
ll tot, pass;

void cal(vector<int> &ar, vector<pii> &piece, vector<int> &help) {
    ll sum = 0, startIdx = 0;
    rep(i, n) {
        sum += ar[i];
        if(sum >= pass) {
            while(sum >= pass && startIdx <= i) {
                sum -= ar[startIdx];
                startIdx++;
            }
            piece.push_back({startIdx - 1, i});
        }
    }
    int len = piece.size();
    help.resize(len);
    help[len - 1] = piece[len - 1].second;
    for(int i = piece.size() - 2; i >= 0; i--) {
        help[i] = min(piece[i].second, help[i + 1]);
    }
    return;
}

// 0-2 1-3 4-4
int binSearch(vector<pii> &piece, vector<int> &help, int l) {
    int left = 0, right = piece.size() - 1, result = 1e9;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(piece[mid].first >= l) {
            result = help[mid];
            right = mid - 1;
        }
        else left = mid + 1;
    }
    return result;
}

inline void printRes(vector<int> pos, vector<int> order) {
    vector<int> temp(3);
    rep(i, 3) temp[order[i]] = i;
    cout << pos[temp[0]*2] + 1 << " " << pos[temp[0]*2 + 1] + 1 << " ";
    cout << pos[temp[1]*2] + 1 << " " << pos[temp[1]*2 + 1] + 1 << " ";
    cout << pos[temp[2]*2] + 1 << " " << pos[temp[2]*2 + 1] + 1 << '\n';
    return;
}

bool trySol(vector<vector<pii>> &pieces, vector<vector<int>> helpers, vector<int> order) {
    int l1 = pieces[order[0]].size();
    rep(i, l1) {
        int end2 = binSearch(pieces[order[1]], helpers[order[1]], pieces[order[0]][i].second + 1), end3;
        if(end2 < n - 1) {
            end3 = binSearch(pieces[order[2]], helpers[order[2]], end2 + 1);
            if(end3 < n) {
                printRes({0, pieces[order[0]][i].second, pieces[order[0]][i].second + 1, end2, end2 + 1, n - 1}, order);
                return true;
            }
        }
        end3 = binSearch(pieces[order[2]], helpers[order[2]], pieces[order[0]][i].second + 1);
        if(end3 < n - 1) {
            end2 = binSearch(pieces[order[1]], helpers[order[1]], end3 + 1);
            if(end2 < n) {
                printRes({0, pieces[order[0]][i].second, end3 + 1, n - 1, pieces[order[0]][i].second + 1, end3}, order);
                return true;
            }
        }
    }
    return false;
}

void sol(){
    cin >> n;
    rep(i, n) cin >> arr[i];
    rep(i, n) cin >> brr[i];
    rep(i, n) cin >> crr[i];

    tot = 0;
    rep(i, n) tot += arr[i];
    pass = ceil(static_cast<float>(tot)/3);
    vector<vector<pii>> pieces(3, vector<pii>());
    vector<vector<int>> helpers(3, vector<int>());
    
    cal(arr, pieces[0], helpers[0]);
    cal(brr, pieces[1], helpers[1]);
    cal(crr, pieces[2], helpers[2]);

    // A first
    if(trySol(pieces, helpers, {0, 1, 2})) return;
    // B first
    if(trySol(pieces, helpers, {1, 0, 2})) return;
    // C first
    if(trySol(pieces, helpers, {2, 0, 1})) return;
    cout << "-1\n";
    return;
}

int main(){_
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t; cin >> t;
    while(t--){
        sol();
    }
    return 0;
}