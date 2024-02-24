// https://codeforces.com/contest/1907/problem/B

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

void sol(){
    string s; cin >> s;
    stack<char> st;
    int smol = 0, big = 0;
    FOD(i, s.size() - 1, 0){
        if(s[i] == 'b') smol++;
        else if(s[i] == 'B') big++;
        else{
            if(islower(s[i]) && smol){
                smol--;
                continue;
            }
            if(isupper(s[i]) && big){
                big--;
                continue;
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
    cout << endl;
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